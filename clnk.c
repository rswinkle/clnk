
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char* read_null_term(FILE* f, int offset, char* out_buf, int size)
{
	fseek(f, offset, SEEK_SET);

	char* s = out_buf;
	int i=0;
	do {
		if (!fread(&s[i], 1, 1, f)) {
			s[i] = 0;
			return NULL; // TODO hmm
		}
		i++;
	} while (s[i-1] && i < size);

	if (s[i-1]) {
		s[i] = 0;
		return NULL;
	}
	return s;
}


int main(int argc, char** argv)
{

	if (argc != 2) {
		printf("Usage: %s some_shortcut.lnk\n", argv[0]);
		return 0;
	}

	FILE* f = fopen(argv[1], "rb");
	if (!f) {
		perror("Couldn't open file");
		return 0;
	}

	fseek(f, 76, SEEK_SET);

	// assume LSB machine for now
	uint16_t items;
	fread(&items, 2, 1, f);
	printf("items = %u\n", items);

	int struct_start = 78 + items;
	int base_path_off_off = struct_start + 16;

	uint32_t base_path_off;
	fseek(f, base_path_off_off, SEEK_SET);
	fread(&base_path_off, 4, 1, f);
	printf("base_path_off: %u\n", base_path_off);

	base_path_off += struct_start;
	char path[1024];
	if (read_null_term(f, base_path_off, path, sizeof(path))) {
		printf("Path: %s\n", path);
	}

	


	fclose(f);



	return 0;
}
