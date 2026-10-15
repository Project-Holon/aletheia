/*
 * function: WIFIBATTLEMATCH_NET_TaskMain
 * address: 0x021D44D4
 * packet: pkt_ov175_021D44D4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent tail 021D458A..021D458C is two zero alignment bytes before 021D458C.
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021E8A80 0x021E8A80 thumb ov177
 *   func_021E8A90 0x021E8A90 thumb ov177
 *   WIFIBATTLEMATCH_NET_Noop 0x021D9ED0 thumb ov175
 *   WIFIBATTLEMATCH_GRAPHIC_Draw 0x021E5534 thumb ov177
 *   func_021E867C 0x021E867C thumb ov177
 *   func_021E7E08 0x021E7E08 thumb ov177
 *   func_021E5980 0x021E5980 thumb ov177
 *   func_021E64C0 0x021E64C0 thumb ov177
 *   func_021E7774 0x021E7774 thumb ov177
 */
typedef signed int     s32;
typedef unsigned int   u32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
typedef unsigned char  u8;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void func_021E8A80(unsigned);
extern int func_021E8A90(int **p);
extern void WIFIBATTLEMATCH_NET_Noop(int);
extern void WIFIBATTLEMATCH_GRAPHIC_Draw(u8 *p);
extern void func_021E867C(char *p);
extern void func_021E7E08(int);
extern void func_021E5980(int);
extern int func_021E64C0(unsigned char *,void *);
extern int func_021E7774(void *p, void *mgr);
int WIFIBATTLEMATCH_NET_TaskMain(unsigned sys,int *state,int unused,int *p)
{
    switch(*state) {
    case 0: FADE_Start(3,16,0,0); *state=1; break;
    case 1: if(FADE_IsActive()==0) *state=2; break;
    case 2:
        func_021E8A80(p[13]);
        if(func_021E8A90((int **)p[13])) *state=3;
        if(p[12]) WIFIBATTLEMATCH_NET_Noop(p[12]);
        break;
    case 3: FADE_Start(3,0,16,0); *state=4; break;
    case 4: if(FADE_IsActive()==0) return 1; break;
    }
    WIFIBATTLEMATCH_GRAPHIC_Draw((u8 *)p[0]);
    PRINTSYS_QUE_Main((struct PrintSys *)p[3]);
    func_021E867C((char *)p[9]);
    func_021E7E08(p[8]);
    func_021E5980(p[1]);
    if(p[6]) func_021E64C0((unsigned char *)p[6],(void *)p[3]);
    if(p[7]) func_021E7774((void *)p[7],(void *)p[3]);
    return 0;
}
