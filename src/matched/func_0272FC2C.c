/*
 * function: func_0272FC2C
 * address:  0x0272FC2C
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   data_02732EFC 0x02732EFC data twl
 *   func_0272F9C4 0x0272F9C4 arm twl
 */

extern char data_02732EFC[];
void func_0272F9C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, void *a8, int a9, unsigned int a10);

void func_0272FC2C(int a0, int a1, int a2, int a3, int a4, int a5)
{
    func_0272F9C4(1, a0, a1, a2, 0, a3, a4, a5, (void *)(data_02732EFC + (a0 << 4)), -1, 0x80000000);
}
