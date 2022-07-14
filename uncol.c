
#include <string.h>
#include <stdio.h>

int
	main(int argc, char *argv[])
{
	char inbuf[1024];
	char utbuf[1024];
	char vunit[1024];
	char needle[64];
	char **ms, *mss[] = { "05D", "038Th", 0 };
	char *ut;
	int found;
	int newvu = 0;

	while (fgets(inbuf, sizeof inbuf, stdin)) {
		switch (inbuf[0]) {
		case '@':
			fputs(inbuf, stdout);
			break;
		case '>':
			fputs(inbuf+6, stdout);
			break;
		case '^':
			strcpy(vunit, inbuf+1);
			newvu = 1;
			break;
		case '=':
			found = 0;
			ut = utbuf;
			ut += sprintf(ut, "      %c", inbuf[1]);
			for (ms = argv+1; *ms; ms++) {
				sprintf(needle, " %s ", *ms);
				if (strstr(inbuf, needle)) {
					found = 1;
					ut += sprintf(ut, " %s", *ms);
				}
			}
			ut += sprintf(ut, "\n");
			if (found) {
				if (newvu)
					fputs(vunit, stdout);
				fputs(utbuf, stdout);
				newvu = 0;
			}
		}
	}
	return 0;
}
