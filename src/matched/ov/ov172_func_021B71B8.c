/*
 * function: CTVT_CAMVIEW_UploadWindows
 * address: 0x021B71B8
 * packet: pkt_ov172_021B71B8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMM_TVT_SYS_GetLayoutMode 0x021BE05C thumb ov172
 *   COMM_TVT_SYS_GetHalfRes 0x021BE078 thumb ov172
 *   COMM_TVT_SYS_GetComm 0x021BDFE4 thumb ov172
 *   COMM_TVT_SYS_GetMemberCount 0x021BE054 thumb ov172
 *   COMM_TVT_SYS_ClearAndTransferNameWindows 0x021BE1E4 thumb ov172
 *   CTVT_COMM_GetSlotConnected 0x021B8B8C thumb ov172
 *   CTVT_COMM_GetSlotReady 0x021B8BAC thumb ov172
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207ECF0 0x0207ECF0 arm
 *   G2_GetBG3ScrPtr 0x0207E100 arm
 *   func_02082A7C 0x02082A7C arm
 *   FX_Inv 0x0207C778 arm
 *   func_0207D59C 0x0207D59C arm
 *   APP_ENV_HasParentalControlBits 0x0202EB14 thumb
 *
 * note 2026-10-05 (wD9 lane06): EXACT. The last 4-byte residue (m[3] store and
 *   `movs r5,#0` swapped) closed with the two FX_Inv calls and m[0]/m[3]
 *   stores written in each arm of `if (q->f20 == 1)` with literal 0x2000/0x1000.
 *   Cross-jumping merges the two arms into one tail (movs r5,#1/#2 then a shared
 *   lsls), so the join label sits after the m[3] store and the zero for m[1], m[2]
 *   and the stack arguments is built in the next block. Earlier lanes (D3 to D8)
 *   closed the rest: sub == 0 as if/else, raw halve stores, dst as a u32 address,
 *   the row term as a loop local, arg orders of the copy call.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ent {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u8 pad[0xC];
} Ent;

typedef struct Q {
    u32 f0;
    char *f4;
    char *f8;
    char *fC;
    u8 f10;
    u8 pad11[3];
    int f14;
    int f18;
    int f1c;
    u32 f20;
    u8 pad24[8];
    u8 f2c;
    u8 f2d;
    u8 pad2e[2];
    int f30;
    u8 pad34[0xC];
    Ent ent[4];
} Q;

extern int COMM_TVT_SYS_GetLayoutMode(void *p);
extern u32 COMM_TVT_SYS_GetHalfRes(void *p);
extern u32 COMM_TVT_SYS_GetComm(void *p);
extern u8 COMM_TVT_SYS_GetMemberCount(void *p);
extern void COMM_TVT_SYS_ClearAndTransferNameWindows(u8 *p);
extern u32 CTVT_COMM_GetSlotConnected(int unused, char *base, int i);
extern u8 CTVT_COMM_GetSlotReady(void *unused, char *base, int i);
extern void DWCi_ScreenDC_FlushRange(void *p, u32 n);
extern void func_0207ECF0(const void *src, u32 off, u32 size);
extern void *G2_GetBG3ScrPtr(void);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern int FX_Inv(int);
extern void func_0207D59C(void *, int *, int, int, int, int);
extern int APP_ENV_HasParentalControlBits(void);

void CTVT_CAMVIEW_UploadWindows(void *p, Q *q)
{
    int sub;
    u32 wide;
    u32 base;
    u32 dst;
    int h;
    int bit;
    u8 i;
    int m[4];

    sub = COMM_TVT_SYS_GetLayoutMode(p);
    wide = COMM_TVT_SYS_GetHalfRes(p);
    base = COMM_TVT_SYS_GetComm(p);
    if (COMM_TVT_SYS_GetMemberCount(p) < 2)
        return;
    if (sub == 0) {
        if (q->f10 != 0) {
            DWCi_ScreenDC_FlushRange((u16 *)q->f4, 0x18000);
            func_0207ECF0(q->f4, 0, 0x18000);
            q->f10 = 0;
        }
    } else {
        if (q->f14 == 1) {
            u8 n = 0;
            for (i = 0; i < 4; i++) {
                if ((1 << i) & q->f10)
                    n++;
            }
            if (n != COMM_TVT_SYS_GetMemberCount(p))
                return;
            if (q->f2c < 2) {
                q->f10 = 0;
                q->f2c++;
                for (i = 0; i < 4; i++) {
                    if (CTVT_COMM_GetSlotConnected((int)p, (char *)base, i) == 1 && CTVT_COMM_GetSlotReady(p, (char *)base, i) == 0)
                        q->f10 |= (u8)(1 << i);
                }
                return;
            }
            if (q->f2d < 0xC0)
                return;
            if (q->f18 == 1) {
                q->f2d = 0;
                q->f30 = 1;
                q->f18 = 0;
                *(volatile u16 *)0x04000040 = 0xFF;
                *(volatile u16 *)0x04000044 = 0;
                *(volatile u16 *)0x04000042 = 0x8000;
                *(volatile u16 *)0x04000046 = 0;
            }
            if (q->f1c == 1) {
                q->f1c = 0;
                COMM_TVT_SYS_ClearAndTransferNameWindows(p);
            }
            func_02082A7C(0, G2_GetBG3ScrPtr(), 0x18000);
            q->f14 = 0;
            if (q->f20 != COMM_TVT_SYS_GetHalfRes(p)) {
                q->f20 = COMM_TVT_SYS_GetHalfRes(p);
                if (q->f20 == 1) {
                    m[0] = FX_Inv(0x2000);
                    m[3] = FX_Inv(0x2000);
                } else {
                    m[0] = FX_Inv(0x1000);
                    m[3] = FX_Inv(0x1000);
                }
                m[1] = 0;
                m[2] = 0;
                func_0207D59C((void *)0x04000030, m, 0, 0, 0, 0);
                for (i = 0; i < 4; i++) {
                    if (q->f20 == 1) {
                        *(u16 *)((u8 *)q + 0x48 + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x48 + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x4A + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x4A + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x4C + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x4C + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x4E + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x4E + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x40 + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x40 + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x42 + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x42 + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x44 + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x44 + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x46 + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x46 + i * 0x1C) >> 1;
                    } else {
                        q->ent[i].a <<= 1;
                        q->ent[i].b <<= 1;
                        q->ent[i].c <<= 1;
                        q->ent[i].d <<= 1;
                        q->ent[i].x <<= 1;
                        q->ent[i].y <<= 1;
                        q->ent[i].w <<= 1;
                        q->ent[i].h <<= 1;
                    }
                }
            }
            q->f30 = 0;
        }
        for (i = 0; i < 4; i++) {
            bit = 1 << i;
            if (!(bit & q->f10))
                continue;
            if (CTVT_COMM_GetSlotConnected((int)p, (char *)base, i) == 1) {
                u32 idx = i;
                int w;
                            int j;
                if (sub == 1 && idx != 0)
                    idx = 1;
                if (wide == 0) {
                    w = 0x80;
                    h = (u16)(sub == 1 ? 0xC0 : 0x60);
                } else {
                    w = 0x40;
                    h = (u16)(sub == 1 ? 0x60 : 0x30);
                }
                if (CTVT_COMM_GetSlotReady(p, (char *)base, i) == 1 && APP_ENV_HasParentalControlBits() == 0) {
                    dst = (u32)(q->f4 + idx * (w * h * 2));
                    DWCi_ScreenDC_FlushRange((void *)dst, w * h * 2);
                } else if (wide == 0) {
                    if (sub == 1) {
                        dst = (u32)q->f8;
                        DWCi_ScreenDC_FlushRange((void *)dst, 0xC000);
                    } else {
                        dst = (u32)(q->f8 + 0x3000);
                        DWCi_ScreenDC_FlushRange((void *)dst, 0x6000);
                    }
                } else {
                    if (sub == 1) {
                        dst = (u32)q->fC;
                        DWCi_ScreenDC_FlushRange((void *)dst, 0x3000);
                    } else {
                        dst = (u32)(q->fC + 0xC00);
                        DWCi_ScreenDC_FlushRange((void *)dst, 0x1800);
                    }
                }
                for (j = 0; j < q->ent[i].h; j++) {
                    int r = j + (h - q->ent[i].h);
                    func_0207ECF0((void *)((w - q->ent[i].w) * 2 + (dst + r * w * 2)),
                                  q->ent[i].x * 2 + (j + q->ent[i].y) * 0x200,
                                  q->ent[i].w * 2);
                }
            }
            q->f10 -= (u8)bit;
        }
    }
}
