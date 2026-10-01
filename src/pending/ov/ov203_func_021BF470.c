/*
 * function: func_021BF470
 * address: 0x021BF470
 * packet: pkt_ov203_021BF470
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH*
 * blocker: ARM9 0x0201F614 lacks a witness outside this caller; scratch verification EXACT, 20 bytes.
 *   symbols: func_0203FB44 0x0203FB44 arm
 *   extern void func_0203FB44(unsigned,unsigned short,unsigned short);
 *   void func_0201F614(unsigned a,unsigned b) { func_0203FB44(a,(unsigned short)b,b>>16); }
 * padding: 0x021BF4C2..0x021BF4C4 is zero alignment padding.
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_0201F614 0x0201F614 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_0204047C 0x0204047C arm
 *   func_02040588 0x02040588 arm
 */
extern void func_0201CE48(void *),func_02045808(void *),func_0201DD68(void),func_0201F7A8(void *,unsigned),func_020452E8(void *),func_0201F614(int,int),func_02082BCC(void *,int,int),func_0204047C(int,unsigned short),func_02040588(unsigned,unsigned);
void func_021BF470(char *p)
{
    if(*(void **)(p+0x20)) func_0201CE48(*(void **)(p+0x20));
    func_02045808(*(void **)(p+0x24));func_0201DD68();
    func_0201F7A8(*(void **)(p+0x1C),1);func_020452E8(*(void **)(p+0x1C));
    func_0201F614(1,*(int *)(p+0x18));func_02082BCC(p,0,0x28);
    func_0204047C(1,1);func_0204047C(0,0);func_02040588(1,0);
}
