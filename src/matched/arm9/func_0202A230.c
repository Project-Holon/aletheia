/*
 * function: TPOKE_DATA_GetRecordField
 * address:  0x0202A230
 * packet:   pkt_0202A230
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   TPOKE_DATA_ReadRecord  0x0202A3AC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void TPOKE_DATA_ReadRecord(void *a, void *out);

typedef struct {
    u8  b0;
    u8  b1;
    u8  b2;
    u8  b3;
    u16 w[4];
    u32 d;
    u8  f : 1;
    u8  b11;
    u16 h12;
} Buf;

u32 TPOKE_DATA_GetRecordField(void *a, u32 idx)
{
    Buf buf;
    u32 r;

    TPOKE_DATA_ReadRecord(a, &buf);
    switch (idx) {
    case 0:
        r = buf.b0;
        break;
    case 1:
        r = buf.b1;
        break;
    case 2:
        r = buf.b2;
        break;
    case 3:
        r = buf.b3;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        r = buf.w[idx - 4];
        break;
    case 8:
        r = buf.d;
        break;
    case 9:
        r = buf.f;
        break;
    case 10:
        r = buf.b11;
        break;
    case 11:
        r = buf.h12;
        break;
    }
    return r;
}
