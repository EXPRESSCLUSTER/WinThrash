#include <windows.h>
#include <stdio.h>

//#define DEBUG
#define TEN_MB	(10 * 1024 * 1024)
#define COUNT	(1000)

#ifdef DEBUG
void dump(UCHAR**);
#endif

int main()
{
	UCHAR* ptrs[COUNT] = { NULL };
	UCHAR* p = NULL;
	int cnt = 0;
	int i, j;

	for (i = 0; i < COUNT; i++) {
		p = malloc(TEN_MB);
		if (p == NULL) {
			break;
		}
		ptrs[i] = p;
	}
	printf("%d MB allocated\n", i * 10);

	#ifdef DEBUG
	dump((UCHAR**)&ptrs);
	#endif

	for (j = 0; j < i; j++) {
		memset(ptrs[j], 0xff, TEN_MB);
	}

	#ifdef DEBUG
	dump((UCHAR**)&ptrs);
	#endif

	return 0;
}

#ifdef DEBUG
void dump(unsigned char** p) {
	for (int i = 0; i < 10; i++) {
		printf("%x ", **(p + i));
	}
	printf("\n");
#endif}