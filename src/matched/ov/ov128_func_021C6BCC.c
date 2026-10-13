/*
 * function: func_021C6BCC
 * address: 0x021C6BCC
 * packet: pkt_ov128_021C6BCC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   MYSTATUS_Create 0x0200846C thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_020099D4 0x020099D4 thumb
 *   STRBUF_SetString 0x02045924 arm
 *   func_020084E4 0x020084E4 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00329.h"
#include "../include/Obj10485.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct BigObj;
extern unsigned int GAME_DATA_GetWifiList(const struct BigObj *p);
extern void *MYSTATUS_Create(int);
typedef unsigned int   u32;
struct Sub020097BCEnt;
struct Sub020097BCObj;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct Sub020097BCEnt *func_020099D4(struct Sub020097BCObj *obj, int i);
struct Strbuf;
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u32 func_020307B0(void *p);
void func_021C6BCC(u8 *p,u8 *q,int idx,unsigned heap)
{
    void *base;
    void *obj;
    void *str;
    base=(void *)GAME_DATA_GetWifiList(((struct Obj10485 *)q)->f4);
    obj=MYSTATUS_Create(heap);
    str=STRBUF_Create(10,heap);
    STRBUF_SetString(str,(const u16 *)func_020099D4(base,idx));
    func_020084E4(obj,str);
    STRBUF_Delete(str);
    func_0201F02C(((struct Obj00329 *)p)->f0,0,obj);
    func_020307B0(obj);
}
