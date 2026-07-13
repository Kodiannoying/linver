#include <stdio.h>
#include <sys/utsname.h>
#include <unistd.h>

int main() {
	struct utsname info;
	FILE *file = fopen("/etc/osinfo", "r");
	char c;
	char line[256];

	if (!file) {
		printf("linver /etc/osinfo not found!\n");
		perror("Error");
	} else {
		printf("== Linver v1 ==\n");
		printf("\n");
		while (fgets(line, sizeof(line), file)) {
			char key[128];
			char value[128];

			if (sscanf(line, "%127[^=]=%127[^\n]", key, value) == 2) {
				printf("%s: %s\n", key, value);
			}
		}
		printf("\n");
		printf("== Linver v1 ==\n");
		fclose(file);
	}
	return 0;
}
