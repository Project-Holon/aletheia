/*
 * function: BTL_REC_ReadRecord
 * address:  0x021EE6B8
 * packet:   pkt_ov093_021EE6B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the next record for channel idx from a packed byte stream. Header byte:
 * bits 0-3 count, bits 4-6 type, bit 7 flag. Type 1 carries count sub-records
 * (bits 0-4 size in words, bits 5-7 channel); the one for idx is copied into
 * buf[idx]. Type 2 is a skip, type 3 resets buf[idx]. Any error sets err.
 * The final bounds check reads len and pos into separate locals: that keeps
 * the len shift pair ahead of the pos load.
 *
 * symbols:
 *   BTL_ACTION_SetRecordError  0x021D8470  thumb
 *   BTL_ACTION_SetRecordReset  0x021D845C  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 *data;          /* 0x00 */
    u32 len : 31;      /* 0x04 */
    u32 err : 1;
    u32 pos[4];        /* 0x08 */
    u32 buf[4][16];    /* 0x18 */
} Reader;

void BTL_ACTION_SetRecordError(u32 *p);
void BTL_ACTION_SetRecordReset(u32 *p);
void MI_CpuCopy8(const void *src, void *dst, u32 n);

u32 *BTL_REC_ReadRecord(Reader *r, u32 idx, u8 *outLen, u8 *outFlag)
{
    u32 *pos;
    u32 p0;
    if (r->err) {
        BTL_ACTION_SetRecordError(r->buf[idx]);
        *outLen = 1;
        *outFlag = 0;
        return r->buf[idx];
    }
    pos = r->pos;
    while ((p0 = pos[idx]) < r->len) {
        u8 b = r->data[p0];
        u8 count = b & 0xF;
        int type = (b >> 4) & 7;
        *outFlag = (b >> 7) & 1;
        pos[idx]++;
        if (pos[idx] > r->len)
            break;
        if (type == 1) {
            u32 *res = 0;
            u32 i;
            if (count == 0 || count > 4)
                break;
            for (i = 0; i < count; i++) {
                u32 p = pos[idx]++;
                u8 *dd = r->data;
                u8 c = dd[p];
                u8 id = (c >> 5) & 7;
                u8 sz = c & 0x1F;
                if (pos[idx] >= r->len)
                    break;
                if (id != idx) {
                    pos[idx] += sz * 4;
                } else {
                    MI_CpuCopy8(dd + pos[idx], r->buf[idx], sz * 4);
                    res = r->buf[idx];
                    pos[idx] += sz * 4;
                    *outLen = sz;
                }
            }
            if (res)
                return res;
        } else if (type == 3) {
            u32 *res = r->buf[idx];
            BTL_ACTION_SetRecordReset(res);
            *outLen = 1;
            *outFlag = 0;
            return res;
        } else if (type != 2) {
            break;
        }
        {
            u32 len = r->len;
            u32 p = pos[idx];
            if (p >= len)
                break;
        }
    }
    r->err = 1;
    BTL_ACTION_SetRecordError(r->buf[idx]);
    *outLen = 1;
    *outFlag = 0;
    return r->buf[idx];
}
