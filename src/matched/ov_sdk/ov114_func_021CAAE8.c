/*
 * function: func_021CAAE8
 * address:  0x021CAAE8
 * packet:   pkt_ov114_021CAAE8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi_MyFree (libcrypto.TWL.HYB.a(util.o))
 *
 * symbols:
 *   func_020869E8  0x020869E8  arm
 *   g_021D422C     0x021D422C  data
 */

struct CryptoAllocators {
	void (*free_fn)(void *);
	void *(*alloc_fn)(unsigned long);
};

extern void func_020869E8(int id, int heap, void *ptr);
extern struct CryptoAllocators g_021D422C;

void func_021CAAE8(void *ptr)
{
	if (g_021D422C.free_fn != 0)
		g_021D422C.free_fn(ptr);
	else
		func_020869E8(0, -1, ptr);
}
