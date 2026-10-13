/*
 * function: INTRUDE_SUBDISP_CreateDisconnectEvent
 * address:  0x0217CA84
 * packet:   pkt_ov018_0217CA84
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_0202647C  0x0202647C  thumb
 *   GAMESYSTEM_IsNetOffBySleep  0x02012204  thumb
 *   func_020061E4  0x020061E4  thumb
 *   INTRUDE_FIELD_SetSingleAreaMode  0x0217C094  thumb
 *   INTRUDE_SUBDISP_DisconnectEventMain  0x0217CAFC  thumb
 */

typedef struct {
    unsigned char pad00[0x20];
    int f20;
    int f24;
} Ov018Work;

struct Ctx;
unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *);
struct Desc;
struct Desc *func_020122C0(void *owner, void *a, void *b, unsigned int size);
struct Obj;
void *func_020124E8(struct Obj *p);
typedef unsigned int   u32;
u32 func_02026454(void *obj);
u32 func_02026474(void *obj);
u32 func_0202647C(void *obj);
u32 GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
void func_020061E4(u32 a);
void INTRUDE_FIELD_SetSingleAreaMode(unsigned char *);
void INTRUDE_SUBDISP_DisconnectEventMain(void);

int INTRUDE_SUBDISP_CreateDisconnectEvent(void *a, int b)
{
    void *sys;
    int ret;
    Ov018Work *work;
    unsigned char *x;

    sys = (void *)GAMESYSTEM_GetGameComm(a);
    ret = (int)func_020122C0(a, 0, INTRUDE_SUBDISP_DisconnectEventMain, 0x28);
    work = func_020124E8((struct Obj *)ret);
    work->f20 = b;
    if (func_02026454(sys) == 2) {
        x = (unsigned char *)func_02026474(sys);
        if (x != 0) {
            INTRUDE_FIELD_SetSingleAreaMode((unsigned char *)func_02026474(sys));
            x[0x8F8] |= 0x80;
        }
    }
    if (GAMESYSTEM_IsNetOffBySleep(a) == 1) {
        if (func_0202647C(sys) == 1) {
            work->f24 = 1;
        }
    }
    func_020061E4(0x737);
    return ret;
}
