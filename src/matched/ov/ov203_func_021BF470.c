/*
 * function: func_021BF470
 * address: 0x021BF470
 * packet: pkt_ov203_021BF470
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: ARM9 0x0201F614 lacks a witness outside this caller; scratch verification EXACT, 20 bytes.
 *   symbols: func_0203FB44 0x0203FB44 arm
 *   extern void func_0203FB44(unsigned,unsigned short,unsigned short);
 *   void func_0201F614(unsigned a,unsigned b) { func_0203FB44(a,(unsigned short)b,b>>16); }
 * padding: 0x021BF4C2..0x021BF4C4 is zero alignment padding.
 * symbols:
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_0201F614 0x0201F614 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0204047C 0x0204047C arm
 *   func_02040588 0x02040588 arm
 */
typedef unsigned int   u32;
struct Descriptor;
struct Rec3;
struct U16Vec;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201DD68(void);
extern void func_0201F7A8(void *,unsigned);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void func_0201F614(int a, u32 x);
extern void MI_CpuFill8(void *,int,int);
extern void func_0204047C(int,unsigned short);
extern void func_02040588(unsigned char which, unsigned char enable);
void func_021BF470(char *p)
{
    if(*(void **)(p+0x20)) PRINTSYS_PrintStreamDelete(*(void **)(p+0x20));
    STRBUF_Delete(*(void **)(p+0x24));func_0201DD68();
    func_0201F7A8(*(void **)(p+0x1C),1);BMP_WIN_Delete(*(void **)(p+0x1C));
    func_0201F614(1,*(int *)(p+0x18));MI_CpuFill8(p,0,0x28);
    func_0204047C(1,1);func_0204047C(0,0);func_02040588(1,0);
}
