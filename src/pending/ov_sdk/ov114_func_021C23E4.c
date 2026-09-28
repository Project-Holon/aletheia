/*
 * function: func_021C23E4
 * address:  0x021C23E4
 * packet:   pkt_ov114_021C23E4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * near miss (w2_s1): 31 bytes differ: original zeroes the 0x1c-byte block with a 7x4 byte store loop sharing r0=0 with the early return-0 (mov r0,#0 before popeq); here the zero lands in a fresh register and the return is predicated. memset call, indexed loop, hand-unrolled loop, named zero tried.
 *
 * sdk:      ghiNewPost (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 *
 * symbols:
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_021C235C  0x021C235C  arm  ov114
 */

struct Post {
	void *array;
	unsigned char pad0[0x14];
	int f18;
};

extern void *func_0217EAB0(unsigned long size);
extern void *func_02184144(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void func_0217EAE0(void *ptr);
extern void func_021C235C(void *elem);

struct Post *func_021C23E4(void)
{
	struct Post *post;
	unsigned long i;
	unsigned char zero;
	unsigned char *p;

	post = func_0217EAB0(sizeof(struct Post));
	zero = 0;
	if (post == 0)
		return (struct Post *)zero;
	p = (unsigned char *)post;
	for (i = 7; i != 0; i--) {
		p[0] = zero;
		p[1] = zero;
		p[2] = zero;
		p[3] = zero;
		p += 4;
	}
	post->f18 = 1;
	post->array = func_02184144(0x18, 0, func_021C235C);
	if (post->array == 0) {
		func_0217EAE0(post);
		return 0;
	}
	return post;
}
