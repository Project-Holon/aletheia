/*
 * function: func_021D1A74
 * address: 0x021D1A74
 * packet: pkt_ov093_021D1A74
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EEC20 0x021EEC20 thumb ov093
 *   func_021BB570 0x021BB570 thumb ov093
 *   func_021B9184 0x021B9184 thumb ov093
 *   func_02082A90 0x02082A90 arm
 *   func_021EA824 0x021EA824 thumb ov093
 *   func_021D3F4C 0x021D3F4C thumb ov093
 *   func_021CD5E0 0x021CD5E0 thumb ov093
 *   d_021F00DC 0x021F00DC data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 wpos, rpos; } Buf;
typedef struct { u8 pad[0x1B2]; unsigned char f0:3; unsigned char flag:1; unsigned char f4:4; } Flags;
typedef int (*Callback)(u8 *, int *, int *);
typedef struct { int code; Callback fn; } Entry;
extern const Entry d_021F00DC[];
extern int func_021EEC20(int, u8 **);
extern int func_021BB570(u8 *, int, void *, u32);
extern void func_021B9184(void *);
extern void func_02082A90(const void *, void *, u32);
extern void func_021EA824(void *);
extern int func_021D3F4C(void *);
extern int func_021CD5E0(Buf *, int *);
int func_021D1A74(u8 *p, int *state)
{
    u8 *args;
    int size;
    u16 len;
    Buf *buf;
    u32 i;
    int code;
again:
    switch (*state) {
    case 0:
        size = func_021EEC20(*(int *)(p + 0x50), &args);
        if (*(u8 **)(p + 0xA0) != 0 && p[0x1AE] != 0 && ((Flags *)p)->flag != 0) {
            if (func_021BB570(*(u8 **)(p + 0xA0), p[0x1AE], args, size) != 0) {
                func_021B9184(*(void **)p);
                ((Flags *)p)->flag = 0;
            }
            p[0x1AE] = 0;
        }
        buf = *(Buf **)(p + 0x134);
        len = size;
        func_02082A90(args, buf + 1, len);
        buf->wpos = len;
        buf->rpos = 0;
        if (p[0x1A9] != 0) {
            p[0x1A9] = 0;
            func_021EA824(*(void **)(p + 0x54));
        }
        (*state)++;
    case 1:
        buf = *(Buf **)(p + 0x134);
        if (buf->rpos == buf->wpos) {
            *state = 4;
            return 1;
        }
        if (func_021D3F4C(p + 0x18) != 0) return 1;
        (*state)++;
    case 2:
        code = func_021CD5E0(*(Buf **)(p + 0x134), (int *)(p + 0x138));
        *(int *)(p + 0x178) = code;
        if (code == 0x5E) return 1;
        for (i = 0; i < 0x5D; i++) {
            if (code == d_021F00DC[i].code) break;
        }
        if (i == 0x5D) {
            *state = 1;
            goto again;
        }
        *(Callback *)(p + 0x17C) = d_021F00DC[i].fn;
        *(int *)(p + 0x180) = 0;
        (*state)++;
    case 3:
        if ((*(Callback *)(p + 0x17C))(p, (int *)(p + 0x180), (int *)(p + 0x138)) != 0) {
            *state = 1;
            goto again;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}
