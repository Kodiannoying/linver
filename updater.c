#include <stdio.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("/bin/wget", "r");
    if (!file) {
        printf("Missing wget\n");
        perror("Error");
        return 1;
    } else {
        printf("updating in 3\n");
        sleep(1);
        printf("updating in 2\n");
        sleep(1);
        printf("updating in 1\n");
        sleep(1);
        printf("Installing to ~/linver/\n");
        system("mkdir ~/linver");
        system("cd ~/linver");
        system("wget https://github.com/Kodiannoying/linver/raw/refs/heads/main/linver -O ~/linver/linver");
        system("wget https://raw.githubusercontent.com/Kodiannoying/linver/refs/heads/main/info.txt -O ~/linver/info.txt");
        system("chmod +x ~/linver/linver");
        printf("info:\n");
        system("cat ~/linver/info.txt");
        printf("\n");
        printf("Done!\n");
    }
    return 0;
}
