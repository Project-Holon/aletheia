/*
 * function: func_021BBA4C
 * address: 0x021BBA4C
 * packet: pkt_ov099_021BBA4C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: binding the window address before the gender-zero call preserves its separate hoist and call site; form/gender declaration order fixes their spills.
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj01245.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u32 POKEPARTY_GetCount(void *);
extern void *POKEPARTY_GetMember(void *,u32);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_02041B6C(u32);
void func_021BBA4C(char *p,void *party)
{
    void *s,*t,*mon;
    int n,i,off;
    u32 species,gender,name,form;
    void **w;
    void *win;
    if (((struct Obj01245 *)p)->f1A0==0)
        ((struct Obj01245 *)p)->f1A0=(void *)BMP_WIN_Create(2,1,5,30,6,15,1);
    func_0201F73C(((struct Obj01245 *)p)->f1A0,2,(u16)(((struct Obj01245 *)p)->f1334),14);
    s=STRBUF_Create(0x40,0x21);
    t=STRBUF_Create(0x40,0x21);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj01245 *)p)->f1A0),255);
    BMP_WIN_ClearScreen(((struct Obj01245 *)p)->f1A0);
    n=POKEPARTY_GetCount(party);
    for (i=0;i<n;i++) {
        mon=POKEPARTY_GetMember(party,i);
        if (POKE_TOOL_GetPartyValue(mon,0x4c,0)==0) {
            species=POKE_TOOL_GetPartyValue(mon,0,0);
            form=POKE_TOOL_GetPartyValue(mon,0xad,0);
            name=POKE_TOOL_GetPartyValue(mon,0x9e,0);
            gender=POKE_TOOL_GetPartyValue(mon,0x6e,0);
            MSGDATA_ReadString(((struct Obj01245 *)p)->fE0,0x74,t);
            func_0201EFA4(((struct Obj01245 *)p)->fDC,0,name,3,0,1);
            func_0201F250(((struct Obj01245 *)p)->fDC,s,t);
            off=i*40;
            PRINTSYS_Print(BMP_WIN_GetBmp(((struct Obj01245 *)p)->f1A0),off+1,32,s,((struct Obj01245 *)p)->fEC);
            if (gender!=2 && ((species!=0x1d && species!=0x20) || form!=0)) {
                if (gender==0) {
                    w=(void **)(p+0x1a0);
                    MSGDATA_ReadString(((struct Obj01245 *)p)->fE0,0x75,t);
                    win=*w;
                } else {
                    MSGDATA_ReadString(((struct Obj01245 *)p)->fE0,0x76,t);
                    win=((struct Obj01245 *)p)->f1A0;
                }
                PRINTSYS_Print(BMP_WIN_GetBmp(win),off+30,16,t,((struct Obj01245 *)p)->fE8);
            }
        }
    }
    STRBUF_Delete(s);
    STRBUF_Delete(t);
    BMP_WIN_MakeScreen(((struct Obj01245 *)p)->f1A0);
    BMP_WIN_TransferChars(((struct Obj01245 *)p)->f1A0);
    func_02041B6C(2);
}
