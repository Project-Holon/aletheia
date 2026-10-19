/*
 * function: INTRUDE_SUBDISP_PrintInfoMessage
 * address:  0x0217E714
 * packet:   pkt_ov018_0217E714
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   ZONEDATA_IsEntralink  0x02013D5C  thumb
 *   ZONEDATA_IsZoneGroup118To120  0x02013D9C  thumb
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   GAME_COMM_PopInfoMessage  0x02026608  thumb
 *   INTRUDE_COMM_IsWarnedWithoutRequest  0x021585BC  thumb  ov010
 *   GAME_DATA_GetMyStatusByNetId  0x021583EC  thumb  ov010
 *   INTRUDE_COMM_SetWordSetMemberName  0x021762C0  thumb  ov011
 *   INTRUDE_COMM_SetWordSetRequest  0x021762D8  thumb  ov011
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PALACE_SYS_IsZoneFlagSet  0x021D3554  thumb  ov021
 *   INTRUDE_FIELD_FindZonePos  0x0217BEA8  thumb  ov018
 *   INTRUDE_SUBDISP_IsZoneMatch  0x0217EC08  thumb  ov018
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    unsigned int id : 10;
    unsigned int id2 : 10;
    unsigned int rest : 12;
    u8 pad04[0x0A - 0x04];
    u8 x;
    u8 y;
} Mon;

typedef struct {
    Mon *mon;
    u16 id;
    u16 pad06;
} Slot;

typedef struct {
    u8 pad00[4];
    unsigned int a : 4;
    unsigned int b : 3;
    unsigned int c : 11;
    unsigned int d : 14;
    u8 pad08[0x18 - 0x08];
    u8 f18[0x28 - 0x18];
    u8 f28;
} Sel;

typedef struct {
    u32 f00;
    u8 pad04[0x1C - 0x04];
    int f1C;
    u8 pad20[0x24 - 0x20];
    void *f24;
    int f28;
    void *f2C;
    void *f30;
    u8 pad34[0x38 - 0x34];
    void *f38;
    void *f3C;
    u8 pad40[0x4C - 0x40];
    void *f4C;
    u8 f50;
    u8 pad51[0xD8 - 0x51];
    u8 fD8;
    u8 padD9[0xDC - 0xD9];
    int fDC;
    u8 padE0[0xE4 - 0xE0];
    Sel *fE4;
    u8 fE8;
    u8 fE9;
    u8 fEA;
    u8 padEB[0xEC - 0xEB];
    Slot slots[3];
    u8 pad104[0x108 - 0x104];
    s16 f108;
    u8 pad10A[0x10D - 0x10A];
    u8 f10D;
    u8 f10E;
    u8 pad10F[0x169 - 0x10F];
    u8 f169;
} W;

typedef struct { unsigned short a : 9; unsigned short b : 6; unsigned short c : 1; } Fld;

typedef struct { int x; int y; int z; } Vec3;

typedef struct {
    u32 ptr[2];
    u8 slot[2];
    u8 par[2];
    u16 msg;
} Buf;

struct Ctx;
struct Descriptor;
struct CharBuf;
struct WordSet;
struct MsgBank;
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
struct VecFx32;
u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);
struct BigObj;
int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
u32 ZONEDATA_IsEntralink(u32 id);
u32 ZONEDATA_IsZoneGroup118To120(u32 id);
int GFL_NET_GetNegotiationNum(void);
void *BMP_WIN_GetBmp(struct Descriptor *a0);
void BMP_Clear(struct CharBuf *buf, u8 value);
void BMP_WIN_TransferChars(struct Descriptor *a0);
void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
int GAME_COMM_PopInfoMessage(u8 *p, u8 *out);
int INTRUDE_COMM_IsWarnedWithoutRequest(int a0);
int GAME_DATA_GetMyStatusByNetId(void *a0, int a1);
void INTRUDE_COMM_SetWordSetMemberName(void *win, u32 slot, u8 *src, u16 heap);
void INTRUDE_COMM_SetWordSetRequest(const void *obj, void *a1, void *a2, void *a3);
struct Obj00020;
void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
void FIELD_PLAYER_GetPos(u8 *p, struct VecFx32 *out);
int FIELD_PALACE_SYS_IsZoneFlagSet(void *arg0, int arg1);
Mon *INTRUDE_FIELD_FindZonePos(int a0);
int INTRUDE_SUBDISP_IsZoneMatch(u16 a, u16 b, u16 c);

void INTRUDE_SUBDISP_PrintInfoMessage(W *w, u8 *p, u16 q)
{
    u32 sys;
    void *h;
    int done;
    int cur;
    int prev;
    int i;
    int n;
    int msg;
    int off;
    void *t;
    Mon *m1;
    Mon *m2;
    Mon *e;
    Buf b;
    Vec3 v;

    sys = GAMESYSTEM_GetGameComm((const struct Ctx *)w->f00);
    h = GAMESYSTEM_GetGameData((const struct Ctx *)w->f00);
    done = 0;
    if (w->f108 > 0) {
        w->f108--;
        if (w->f108 == 0 && p == 0) {
            BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp((struct Descriptor *)w->f4C), done);
            BMP_WIN_TransferChars((struct Descriptor *)w->f4C);
        }
        return;
    }
    prev = w->f10D;
    w->f10D = 0;
    cur = GAME_DATA_GetOwnNetId(h);
    if (p != 0 && GFL_NET_GetNegotiationNum() <= 1) {
        off = 0x93A;
        n = p[off - 0x15];
        if (n != 0) {
            if (n == 1) {
                msg = 0x29;
            } else {
                msg = 0x2A;
            }
            for (i = 0; i < p[off - 0x15]; i++) {
                WORDSET_SetSlotTag((struct WordSet *)w->f24, i, *(void **)(p + i * 4 + off - 0x12),
                              p[i + off - 2], 1, p[i + off]);
            }
            MSGDATA_ReadString((struct MsgBank *)w->f2C, msg, w->f38);
            WORDSET_CopyTaggedText((struct WordSet *)w->f24, w->f3C, w->f38);
        } else {
            MSGDATA_ReadString((struct MsgBank *)w->f2C, 0x33, w->f3C);
        }
        done = 1;
    }
    if (done == 0 && p != 0 && GFL_NET_GetNegotiationNum() > 1 && INTRUDE_COMM_IsWarnedWithoutRequest((int)p) != 0) {
        MSGDATA_ReadString((struct MsgBank *)w->f2C, 0x35, w->f3C);
        done = 1;
    }
    if (done == 0 && GAME_DATA_GetIntrudeCount(h) == 0) {
        e = w->slots[cur].mon;
        if (e != 0) {
            for (i = 0; i < 3; i++) {
                if (cur != i && w->slots[i].mon != 0
                    && e->x == w->slots[i].mon->x && e->y == w->slots[i].mon->y) {
                    MSGDATA_ReadString((struct MsgBank *)w->f2C, 0x31, w->f3C);
                    done = 1;
                    break;
                }
            }
        }
        if (done == 0 && w->fE9 == 1) {
            MSGDATA_ReadString((struct MsgBank *)w->f2C, 0x34, w->f3C);
            done = 1;
        }
        if (done == 0 && w->fEA == 1) {
            MSGDATA_ReadString((struct MsgBank *)w->f2C, 0x32, w->f3C);
            done = 1;
        }
    }
    if (done == 0 && p != 0 && w->f169 != 4 && GAME_DATA_GetMyStatusByNetId(h, w->f169) != 0) {
        t = (void *)GAME_DATA_GetMyStatusByNetId(h, w->f169);
        if (((Fld *)(p + w->f169 * 0x1C + 0xA2))->b == 2) {
            msg = 0x36;
        } else {
            msg = 0x28;
        }
        MSGDATA_ReadString((struct MsgBank *)w->f2C, msg, w->f38);
        WORDSET_SetSlotMyStatus((struct WordSet *)w->f24, 0, t);
        WORDSET_CopyTaggedText((struct WordSet *)w->f24, w->f3C, w->f38);
        w->f169 = 4;
        done = 1;
    } else if (w->fDC != 0 && w->fE4 != 0 && (w->fDC == 3 || prev != w->fDC)) {
        if (w->fDC == 3 && p != 0 && w->fE4->a != 4) {
            u32 *ep;
            Mon *mm;
            t = GAMESYSTEM_GetFieldMap((const struct Ctx *)w->f00);
            ep = (u32 *)(p + 0x8C + w->fE4->f28 * 0x1C);
            FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(t), (struct VecFx32 *)(&v));
            INTRUDE_COMM_SetWordSetMemberName(w->f24, 0, w->fE4->f18, 0x70);
            mm = INTRUDE_FIELD_FindZonePos(((u16 *)ep)[10]);
            if (w->fD8 == w->fE8 && mm != 0
                && INTRUDE_SUBDISP_IsZoneMatch(q, mm->id, mm->id2) == 1) {
                if (ep[0] == 1) {
                    MSGDATA_ReadString((struct MsgBank *)w->f2C, 0x2F, w->f38);
                    WORDSET_CopyTaggedText((struct WordSet *)w->f24, w->f3C, w->f38);
                    done = 1;
                } else {
                    int dx = ep[1] - v.x;
                    int dy = ep[3] - v.z;
                    int ady = dy < 0 ? -dy : dy;
                    int adx = dx < 0 ? -dx : dx;
                    if (adx > ady) {
                        msg = 0x2D;
                        if (dx <= 0) {
                            msg = 0x2E;
                        }
                    } else {
                        msg = 0x2C;
                        if (dy <= 0) {
                            msg = 0x2B;
                        }
                    }
                    MSGDATA_ReadString((struct MsgBank *)w->f2C, msg, w->f38);
                    WORDSET_CopyTaggedText((struct WordSet *)w->f24, w->f3C, w->f38);
                    done = 1;
                }
            } else {
                m1 = INTRUDE_FIELD_FindZonePos(((u16 *)ep)[10]);
                m2 = INTRUDE_FIELD_FindZonePos(q);
                if (m1 != 0 && m2 != 0 && m1->x == m2->x && m1->y == m2->y) {
                    MSGDATA_ReadString((struct MsgBank *)w->f2C, 0x2F, w->f38);
                    WORDSET_CopyTaggedText((struct WordSet *)w->f24, w->f3C, w->f38);
                    done = 1;
                }
            }
        }
        if (done == 0 && GAME_DATA_GetIntrudeCount(h) == 1) {
            w->f10D = 0;
            switch (w->fDC) {
            case 1:
                MSGDATA_ReadString((struct MsgBank *)w->f2C, 0x21, w->f3C);
                break;
            case 2:
                MSGDATA_ReadString((struct MsgBank *)w->f2C, 0x22, w->f3C);
                break;
            case 3:
                if (w->f10E == 0) {
                    MSGDATA_ReadString((struct MsgBank *)w->f2C, w->fE4->a + 0x37, w->f3C);
                } else {
                    MSGDATA_ReadString(w->f30, w->fE4->c, w->f38);
                    INTRUDE_COMM_SetWordSetRequest(w->fE4, w->fE4->f18, w->f24, (void *)0x70);
                    WORDSET_CopyTaggedText((struct WordSet *)w->f24, w->f3C, w->f38);
                }
                w->f10E ^= 1;
                break;
            case 0:
            case 4:
                return;
            default:
                return;
            }
            if (w->fDC != 3) {
                w->f10E = 0;
            }
            w->f10D = w->fDC;
            done = 1;
        }
    } else {
        if (GAME_COMM_PopInfoMessage((u8 *)sys, (u8 *)(&b)) == 1) {
            w->f10D = 0;
            MSGDATA_ReadString((struct MsgBank *)w->f2C, b.msg, w->f38);
            done = 1;
            for (i = 0; i < 2; i++) {
                if (b.ptr[i] != 0) {
                    WORDSET_SetSlotTag((struct WordSet *)w->f24, b.slot[i], (void *)b.ptr[i], b.par[i], 1, 2);
                }
            }
            WORDSET_CopyTaggedText((struct WordSet *)w->f24, w->f3C, w->f38);
            done = 1;
        }
    }
    if (done == 0 && GAME_DATA_GetIntrudeCount(h) == 1 && ZONEDATA_IsEntralink(q) == 0 && ZONEDATA_IsZoneGroup118To120(q) == 0
        && FIELD_PALACE_SYS_IsZoneFlagSet(h, q) == 0) {
        MSGDATA_ReadString((struct MsgBank *)w->f2C, 0x30, w->f3C);
        done = 1;
    }
    w->f169 = 4;
    if (done == 1) {
        BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp((struct Descriptor *)w->f4C), 0);
        n = w->f28;
        PRINTSYS_PrintQueColor((void *)n, (int)BMP_WIN_GetBmp((struct Descriptor *)w->f4C), 0, 0, (u32)w->f3C, w->f1C, 0x3C40);
        w->f50 = 1;
        w->f108 = 0x5A;
    }
}
