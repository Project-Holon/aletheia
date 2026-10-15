/*
 * function: CTVT_CALL_DeleteText
 * address:  0x021BDC70
 * packet:   pkt_021B6A00
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Releases the five handles at +0x1dc down to +0x1c8 through a running slot index.
 *
 * symbols:
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct PrintSys;
struct Rec;
struct S02031140;
extern void TIME_ICON_Delete(u8 *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);

void CTVT_CALL_DeleteText(u32 *a0)
{
    u32 i;
    u32 v;

    i = 0x77;
    v = a0[i];
    if (v != 0) {
        TIME_ICON_Delete((u8 *)v);
        a0[i] = 0;
    }
    i = 0x76;
    TCBL_Destroy((struct S02031140 *)a0[i]);
    PRINTSYS_QUE_Clear((struct PrintSys *)a0[i - 2]);
    PRINTSYS_QUE_Delete((struct PrintSys *)a0[i - 2]);
    MSGDATA_Delete((struct Rec *)a0[i - 3]);
    GF_FONT_Delete((void *)a0[i - 4]);
}
