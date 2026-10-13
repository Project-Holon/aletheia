/*
 * function: func_021C0AEC
 * address: 0x021C0AEC
 * packet: pkt_ov099_021C0AEC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x0203CB00 has no outside code witness; its blx at
 *   021C0B16 is the only open site, every other relocation resolves.
 * blocker: 0x0203CB00 ARM verified MATCH, 52 bytes, wave 82 R9 leaf run.
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_FatalError) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; GFL_NET_STATE_FatalError 0x0203CADC arm.
 *   Leaf's only unresolved site is ARM9 0x0203CADC.
 * note: the earlier DIFF338 came from a guard-then-return spelling of the
 *   record compare; the image places the mismatch arm (021C0BDE) before the
 *   early return (021C0BFC), so the test is written as `!= || !=` with the
 *   return in the else.
 * volatile: none.
 * symbols:
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   func_021B9AE0 0x021B9AE0 thumb ov099
 *   func_021BE900 0x021BE900 thumb ov099
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021C08F8 0x021C08F8 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
struct Obj;
extern s32 BMP_MENULIST_Main(struct Obj *);
extern u8 func_021B97F4(char *);
extern void *func_021BE2A8(char *, int);
extern int GFL_NET_STATE_IsFatalError(void);
extern int func_021BA8BC(void *);
extern void BMP_MENULIST_Delete(struct Obj *, u16 *, u16 *);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void func_021B9AE0(void *, u8 *);
extern void func_021BE900(char *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void func_021BA874(char *, int);
extern void func_021BAAB8(char *, int, int);
extern int func_021C23B8(int);
extern u8 func_021BDD48(char *, void *);
extern u8 func_021C27E0(void *);
extern u8 func_021BDD54(char *, void *);
extern int func_021C08F8(char *);
extern void func_021BA8EC(char *);
int func_021C0AEC(char *p, int ret)
{
    int changed;
    s32 choice;
    int n;
    u8 *q;
    int state;
    int other;
    changed = 0;
    choice = BMP_MENULIST_Main(*(struct Obj **)(p + 0xbc));
    n = func_021B97F4(p + 0x274);
    q = func_021BE2A8(p, n);
    if (GFL_NET_STATE_IsFatalError()) {
        *(int *)(p + 0x1a4) = func_021BA8BC(*(void **)(p + 0x1a4));
        BMP_MENULIST_Delete(*(struct Obj **)(p + 0xbc), 0, 0);
        BMP_MENUWORK_Delete(*(void **)(p + 0xb8));
        if (q)
            func_021B9AE0(p + 0x274, q);
        func_021BE900(p);
        return ret;
    }
    switch (choice) {
    case -1:
        if (q == 0) {
            BMP_MENULIST_Delete(*(struct Obj **)(p + 0xbc), 0, 0);
            func_021BA874(p, n - 1);
            func_021BAAB8(p, 13, 0);
            *(int *)(p + 0x1cc) = 0x15;
            changed = 1;
        } else {
            state = func_021C23B8(n - 1);
            func_021BDD48(p, (void *)state);
            changed = func_021C27E0((void *)state);
            other = func_021BDD54(p, (void *)state);
            if (other != func_021BDD54(p, p + 0x24c) || changed != func_021C27E0(p + 0x24c)) {
                func_021BA874(p, n - 1);
                func_021BAAB8(p, 13, 0);
                *(int *)(p + 0x1cc) = 0x15;
                changed = 1;
            } else {
                return ret;
            }
        }
        break;
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        *(int *)(p + 0x1cc) = 11;
        break;
    default:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if (choice == 1) {
            *(int *)(p + 0x1cc) = 11;
            func_021C08F8(p);
        } else if (choice == 2) {
            *(int *)(p + 0x1cc) = 0x2e;
        }
        break;
    }
    if (changed == 0)
        func_021BA8EC(p);
    *(int *)(p + 0x1a4) = func_021BA8BC(*(void **)(p + 0x1a4));
    BMP_MENULIST_Delete(*(struct Obj **)(p + 0xbc), 0, 0);
    BMP_MENUWORK_Delete(*(void **)(p + 0xb8));
    if (q)
        func_021B9AE0(p + 0x274, q);
    return ret;
}
