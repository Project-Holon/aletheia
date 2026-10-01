/*
 * function: func_021BA018
 * address: 0x021BA018
 * packet: pkt_ov214_021BA018
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Both packed halves of +74 are narrowed to u16 at 021BA03A..42;
 * the caller extern follows those truncations despite the callee's u32s.
 * extent-tail: 021BA056 alignment padding (two zero bytes).
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02031140 0x02031140 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020452E8 0x020452E8 arm
 */
typedef unsigned short u16;
extern void func_0201CE48(void*);
extern void func_02045808(void*);
extern void func_02031140(void*);
extern void func_0203FB44(unsigned,u16,u16);
extern void func_020452E8(void*);
void func_021BA018(int unused,char*p)
{
    if(*(void**)(p+0x5c))func_0201CE48(*(void**)(p+0x5c));
    if(*(void**)(p+0x78))func_02045808(*(void**)(p+0x78));
    func_02031140(*(void**)(p+0x68));
    func_0203FB44(1,*(unsigned*)(p+0x74),*(unsigned*)(p+0x74)>>16);
    func_020452E8(*(void**)(p+0x6c));
    func_020452E8(*(void**)(p+0x70));
}
