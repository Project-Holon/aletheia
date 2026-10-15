/*
 * function: BOX2_SEQ_DrawBoxName
 * address:  0x021EB7E8
 * packet:   pkt_ov170_021EB7E8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   func_0200785C 0x0200785C thumb
 *   BMP_Clear 0x02043B5C arm
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 */
#include "../include/Obj23973.h"
#include "../include/Obj23974.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Obj;
struct StrObj;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0200785C(void *save, unsigned box, void *dest);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintColor(void *x, short y, short z, void *s, void *w, unsigned short v);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_OAM_UploadChars(struct Obj *o);

void BOX2_SEQ_DrawBoxName(char **p, unsigned box, int i)
{
    void *s = STRBUF_Create(0x14, 0x804C);
    unsigned n;
    func_0200785C(((void **)p[0])[1], box, s);
    BMP_Clear(*(void **)(p[11] + i * 8 + 8), 0);
    n = func_0201D304(s, ((struct Obj23973 *)(p[11]))->f78, 0);
    n = (0x60 - n) / 2;
    PRINTSYS_PrintColor(*(void **)(p[11] + i * 8 + 8), n, 0, s, ((struct Obj23974 *)(p[11]))->f78, 0x440);
    STRBUF_Delete(s);
    BMP_OAM_UploadChars(*(void **)(p[11] + i * 8 + 4));
}
