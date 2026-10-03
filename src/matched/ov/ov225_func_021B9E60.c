/*
 * function: func_021B9E60
 * address: 0x021B9E60
 * packet: pkt_ov225_021B9E60
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021B99F4 0x021B99F4 thumb ov225
 */
struct PrintSys;extern unsigned func_0201C4E4(struct PrintSys *);extern void func_021B99F4(char *);
void func_021B9E60(char *p){func_0201C4E4(*(struct PrintSys **)(p+16));func_0201C4E4(*(struct PrintSys **)(p+20));func_0201C4E4(*(struct PrintSys **)(p+24));func_021B99F4(*(char **)(p+8));}
