/*
 * function: func_021B9CBC
 * address: 0x021B9CBC
 * packet: pkt_ov133_021B9CBC
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4F10 0x021F4F10 thumb ov112
 *   func_021BA20C 0x021BA20C thumb ov133
 *   func_021F5158 0x021F5158 thumb ov112
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_021B9C08 0x021B9C08 thumb ov133
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 */
#include "../include/Obj00004.h"
#include "../include/Obj14153.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned int func_021F4F10(u8 *p);
extern unsigned int func_021BA20C(u8 *p);
extern u8 func_021F5158(void *, int);
typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_021B9C08(u8 *, unsigned int, void *);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
void func_021B9CBC(u8 *p, u8 *entry)
{
    void *manager = (void *)func_021F4F10(*(u8 * *)&((struct Obj00004 *)p)->f1884);
    u8 *data = (u8 *)func_021BA20C(entry);
    int index = func_021F5158(manager, ((struct Obj14153 *)data)->f0);
    void *obj = GF_FONT_Create_EC64(((struct Obj00004 *)p)->f0);
    void *a = func_02045EC0(((struct Obj00004 *)p)->f18DC, ((struct Obj14153 *)data)->f0 + 3);
    void *b = func_02045EC0(((struct Obj00004 *)p)->f18E0, index + 16);
    func_0201EE0C(obj, 0, a, 0, 1, 2);
    func_0201EE0C(obj, 1, b, 0, 1, 2);
    func_021B9C08(p, 3, obj);
    STRBUF_Delete(b);
    STRBUF_Delete(a);
    WORDSET_DeleteStrbufED04(obj);
}
