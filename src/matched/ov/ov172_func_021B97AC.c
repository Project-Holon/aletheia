/*
 * function: func_021B97AC
 * address: 0x021B97AC
 * packet: pkt_ov172_021B97AC
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 final push G3L9: closed (EXACT in c99 and c). The 9E5C call in case 1 needs the 0x800 table offset and
 *   the func_021BA15C result as named locals assigned before the call (pos, off) under #pragma opt_propagation off for
 *   this function: without the pragma the locals are propagated back into the call and the constant order is wrong (10
 *   bytes); with the pragma but no off local it is also 10 bytes; without the pos local 16. About 30 earlier forms
 *   (inline helpers, prototypes, constant spellings) were all 10 bytes off for the same reason.
 * symbols:
 *   func_021B9F4C 0x021B9F4C thumb ov172
 *   func_021B9DF8 0x021B9DF8 thumb ov172
 *   func_021BA0BC 0x021BA0BC thumb ov172
 *   CTVT_ADPCM_ResetEncoder 0x021B69E0 thumb ov172
 *   func_021B9E3C 0x021B9E3C thumb ov172
 *   KEY_GetCont 0x0203630C arm
 *   func_021BA120 0x021BA120 thumb ov172
 *   func_021BA158 0x021BA158 thumb ov172
 *   func_021BA170 0x021BA170 thumb ov172
 *   func_021BA15C 0x021BA15C thumb ov172
 *   func_021B9E5C 0x021B9E5C thumb ov172
 *   COMM_TVT_SYS_GetComm 0x021BDFE4 thumb ov172
 *   func_021B8C34 0x021B8C34 thumb ov172
 *   func_021B8B74 0x021B8B74 thumb ov172
 *   func_021BA174 0x021BA174 thumb ov172
 *   func_021B891C 0x021B891C thumb ov172
 *   func_021B8740 0x021B8740 thumb ov172
 *   COMM_TVT_SYS_GetTalkStatus 0x021BDFEC thumb ov172
 *   func_021BA244 0x021BA244 thumb ov172
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Rec {
    u16 h0;
    u16 h2;
    u8 b4;
    u8 b5;
    u8 b6;
};

struct St {
    u32 state;
    u32 sub;
    u8 pad08[5];
    u8 b0d;
    u8 pad0e[2];
    u32 *f10;
    u32 f14;
    u8 b18;
    u8 pad19[7];
    struct Rec *f20;
    void *f24;
    u8 pad28[4];
    void *f2c;
    u8 pad30[0x74];
    u32 fa4;
};

struct CharBuf;
struct Descriptor;
extern int func_021B9F4C(int a, int b, int mode);
extern int func_021B9DF8(void *p, int *out);
extern int func_021BA0BC(u32 *p);
extern void CTVT_ADPCM_ResetEncoder(void);
extern void func_021B9E3C(void *p, char *q);
extern u32 KEY_GetCont(void);
extern int func_021BA120(u32 *p);
extern u32 func_021BA158(u32 *p);
extern u32 func_021BA170(u32 *p);
extern u32 func_021BA15C(u32 *p);
typedef short s16;
extern void func_021B9E5C(int a0, char *obj, s16 *tbl, u8 a3, int idx, u16 v);
extern u32 COMM_TVT_SYS_GetComm(void *ctx);
extern u32 func_021B8C34(void *ctx, u8 *rec);
extern int func_021B8B74(void *ctx, u8 *rec);
extern int func_021BA174(int unused, void *a, void *buf, unsigned n);
extern int func_021B891C(void *a, char *q, u16 *p);
extern u32 func_021B8740(int a, int b, u8 c, u32 d);
extern int COMM_TVT_SYS_GetTalkStatus(void *ctx);
extern u32 func_021BA244(void *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);

#pragma opt_propagation off
void func_021B97AC(void *ctx, struct St *st)
{
    int mode = func_021B9F4C((int)ctx, (int)st, 1);
    u32 id;
    u32 pos;
    int busy;
    u32 v;
    u32 off;

    if (func_021B9DF8(ctx, (int *)st) == 1)
        return;
    switch (st->sub) {
    case 0:
        if (func_021BA0BC(st->f10) == 1) {
            st->fa4 = 1;
            st->sub = 1;
            st->b18 = 0;
            st->f14 = 0;
            CTVT_ADPCM_ResetEncoder();
            func_021B9E3C(ctx, (char *)st);
            return;
        }
        break;
    case 1:
        if (mode != 1 && (KEY_GetCont() & 0x101) == 0)
            func_021BA120(st->f10);
        if (func_021BA158(st->f10) == 0) {
            st->sub = 2;
            st->fa4 = 2;
        }
        v = func_021BA170(st->f10);
        pos = func_021BA15C(st->f10);
        off = 0x800;
        func_021B9E5C((int)ctx, (char *)st, (s16 *)(v + off), 9, pos, 0xC000);
    case 2:
        id = COMM_TVT_SYS_GetComm(ctx);
        if (func_021B8C34(ctx, (u8 *)id) != 1)
            break;
        busy = func_021B8B74(ctx, (u8 *)id);
        pos = func_021BA15C(st->f10);
        if (st->f14 == 0 && busy == 0) {
            if (pos >= (u32)(st->b18 + 1) << 11 || st->sub == 2) {
                int n = func_021BA174((int)st->f10, (u8 *)func_021BA170(st->f10) + (st->b18 << 11), st->f24, 0x800);
                st->f20->b5 = st->b18;
                st->f20->h0 = n;
                st->f20->h2 = pos;
                st->f20->b6 = st->b0d;
                st->f20->b4 = (st->sub == 2 && pos <= (u32)(st->b18 + 1) << 11) ? 1 : 0;
                st->f14 = 1;
            }
        }
        if (st->f14 == 1) {
            if (func_021B891C(ctx, (char *)id, (u16 *)st->f20) == 1) {
                st->b18++;
                st->f14 = 0;
                if (st->f20->b4 == 1) {
                    st->sub = 3;
                    return;
                }
            }
        }
        break;
    case 3:
        id = COMM_TVT_SYS_GetComm(ctx);
        if (func_021B8B74(ctx, (u8 *)id) != 0)
            break;
        if (func_021B8740((int)ctx, id, 7, 0) == 1) {
            st->sub = 4;
            BMP_Clear(BMP_WIN_GetBmp(st->f2c), 0);
            BMP_WIN_TransferChars(st->f2c);
            return;
        }
        break;
    case 4:
        if (st->f20->h2 > 0x20) {
            if (func_021BA244((void *)COMM_TVT_SYS_GetTalkStatus(ctx)) == 1) {
                st->sub = 5;
                return;
            }
        } else {
            st->state = 5;
            return;
        }
        break;
    case 5:
        id = COMM_TVT_SYS_GetComm(ctx);
        if (func_021BA244((void *)COMM_TVT_SYS_GetTalkStatus(ctx)) == 0) {
            if (func_021B8740((int)ctx, id, 8, 0) == 1)
                st->state = 5;
        }
        break;
    }
}

#pragma opt_propagation reset
