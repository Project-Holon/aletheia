/*
 * function: WIFICLUB_FreeBgResources
 * address:  0x021BE384
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_0203FB44  0x0203FB44  arm
 *
 * (0x021BE384 is also a function of ov217, filed as src/matched/WIFICLUB_FreeBgResources.c;
 *  this is ov099's byte at that address.)
 *
 * Two guarded releases (each clearing the slot whether or not it was set), then
 * the field at +0x10 and the field at +0x14 each handed to the arm9 routine as
 * a pair of halfwords, low half then high half.
 *
 * Both facts this function was parked on are source shapes:
 *   - the fields are at +0x10 and +0x14, not +0x0C and +0x10.  The parked
 *     spelling had its struct one word short (f08 then immediately f10) and
 *     1.1p1 loaded the wrong word: `ldr r1, [r4, #0xc]`.
 *   - the two arguments are the LOW and the HIGH half of the one u32, not the
 *     same truncated value twice.  The image's
 *     `ldr r2,[r4,#0x10] ; lsls r1,r2,#0x10 ; lsrs r2,r2,#0x10 ; lsls r2,r2,#0x10 ;
 *      lsrs r1,r1,#0x10 ; lsrs r2,r2,#0x10`
 *     is one load, one `(u16)` truncation and one `>> 16`.  Passing `(u16)v`
 *     twice lets 1.1p1 common the two, which is the 10-byte size error and the
 *     register error in one.
 *
 * The listing's extent to the next label is 72 bytes; the last two are the
 * `.byte 0x00, 0x00` alignment before WIFICLUB_DrawTileBlock, so the code is 70.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u32 func_020307B0(void *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);

typedef struct {
    void *f00;
    char pad[4];
    void *f08;
    char pad2[4];
    u32 f10;
    u32 f14;
} S;

void WIFICLUB_FreeBgResources(S *s)
{
    if (s->f00 != 0) {
        func_020307B0(s->f00);
        s->f00 = 0;
    }

    if (s->f08 != 0) {
        func_020307B0(s->f08);
        s->f08 = 0;
    }

    func_0203FB44(1, (u16)s->f10, (u16)(s->f10 >> 16));
    func_0203FB44(6, (u16)s->f14, (u16)(s->f14 >> 16));
}
