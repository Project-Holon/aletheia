/*
 * function: func_0220D7D0
 * address: 0x0220D7D0
 * packet: pkt_ov197_0220D7D0
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 0x0220D7EE.
 * symbols:
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045808 0x02045808 arm
 */
struct WordSet;struct PrintSys;
extern void func_02045C04(void *),func_0201ED04(struct WordSet *),func_0201C4C0(struct PrintSys *),func_02045808(void *);
void func_0220D7D0(char *p){func_02045C04(*(void **)(p+12));func_0201ED04(*(struct WordSet **)(p+16));func_0201C4C0(*(struct PrintSys **)(p+24));func_02045808(*(void **)(p+20));}
