/*
 * function: func_021B7778
 * address: 0x021B7778
 * packet: pkt_ov105_021B7778
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 210-byte code; 021B784A..021B784C is two zero alignment bytes.
 * prototype: 7C94 tail-forwards u32 from own matched 0201C4E4;
 * caller tests r0. The owner's void declaration stays untouched.
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021B7C94 0x021B7C94 thumb ov105
 *   func_021B7DAC 0x021B7DAC thumb ov105
 *   func_021B78BC 0x021B78BC thumb ov105
 *   func_021B85A4 0x021B85A4 thumb ov105
 *   func_021B71E4 0x021B71E4 thumb ov101
 *   func_021B63D0 0x021B63D0 thumb ov101
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Obj { u8 pad[0x78]; int busy; u8 pad7c[6]; u16 counter; } Obj;
extern void func_0204E720(u32,int,int,int);
extern int func_0204E804(void);
extern u32 func_021B7C94(u8 *);
extern int func_021B7DAC(u8 *,u8 *);
extern void func_021B78BC(u8 *),func_021B85A4(u8 *);
extern void func_021B71E4(int);
extern int func_021B63D0(Obj *);
int func_021B7778(void *a,u32 *state,void *b,u8 *p)
{
    Obj *object;
    switch(*state) {
    case 0: *state=1; break;
    case 1: func_0204E720(3,16,0,0); *state=2; break;
    case 2: if(!func_0204E804()) *state=3; break;
    case 3:
        (*(void (**)(u8 *,u16 *))(p+0x18c))(p,(u16 *)(p+0x190));
        if(*(u32 *)(p+0x194)) *state=4;
        break;
    case 4: func_0204E720(3,0,16,0); *state=5; break;
    case 5: if(!func_0204E804()) *state=6; break;
    case 6: return 1;
    }
    if(func_021B7C94(p+0xb0)) {
        func_021B7DAC(p+0xc0,p+0xb0);
        func_021B7DAC(p+0xd4,p+0xb0);
    }
    func_021B78BC(p);
    func_021B85A4(p+0x128);
    func_021B71E4(*(int *)(p+0x188));
    object=*(Obj **)(*(u8 **)(p+0x1a4)+4);
    if(object) func_021B63D0(object);
    return 0;
}
