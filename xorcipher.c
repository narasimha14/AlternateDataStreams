#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void xorcipher(const unsigned char *key, FILE *infp, FILE *outfp){
	int ch;
	const unsigned char *keyp=key;

	while((ch=getc(infp))>=0) {
		putc(ch^*keyp++, outfp);
		if(!*keyp) keyp=key;
	}
}

int main(int argc, char *argv[]){
	char *infname;
	char *outfname;
	const unsigned char *key;
	FILE *infp, *outfp;
    	key = argv[3];
	if(argc>1) infname=argv[1];

	if(!(infp=fopen(infname, "rb"))) {
		fprintf(stderr, "ERROR: fopen(%s)\n", argv[1]);
		exit(1);
	}

	if(argc>2) outfname=argv[2];
	else {
		if(!(outfname=malloc(strlen(infname)+5))) {
			fprintf(stderr, "ERROR: malloc failed\n");
			exit(1);
		}
		strcpy(outfname, argv[1]);
		strcat(outfname, ".xor");

	}

	if(!(outfp=fopen(outfname, "wb"))) {
		fprintf(stderr, "ERROR: fopen(%s)\n", outfname);
		exit(1);
	}


	xorcipher(key, infp, outfp);

	fclose(outfp);
	fclose(infp);

	if(argc<4) free(outfname);

	return 0;
}
