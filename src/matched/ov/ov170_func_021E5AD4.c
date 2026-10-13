/*
 * function: func_021E5AD4
 * address:  0x021E5AD4
 * packet:   pkt_ov170_021E5AD4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02025DE8 0x02025DE8 thumb
 *   KEY_GetRepeat 0x0203633C arm
 *   func_021DD238 0x021DD238 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_020077B8 0x020077B8 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021EBC58 0x021EBC58 thumb
 *   func_020076D0 0x020076D0 thumb
 *   func_021E8F50 0x021E8F50 thumb
 *   func_021E9C94 0x021E9C94 thumb
 *   func_021E9CE0 0x021E9CE0 thumb
 *   func_021E954C 0x021E954C thumb
 *
 * Party list input: L and R page the list when nothing is picked; a pick
 * of the first two rows opens the slot (or refuses it), the others page,
 * jump or cancel.
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
extern int func_02025DE8(struct Sound *obj);
extern unsigned int KEY_GetRepeat(void);
extern void func_021DD238(char *p);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern int func_020077B8(void *save, u32 box);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void func_021EBC58(unsigned char *p, int sel, int kind, int i);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern int func_021E8F50(char *p, int v);
extern int func_021E9C94(char *p, int a, int n);
extern int func_021E9CE0(char *p, int a, int n);
extern int func_021E954C(unsigned char *p, int id, int lo, int arg);

#define WORK(p) (*(char **)((p) + 0x2C))
#define LIST(p) (*(void **)(WORK(p) + 0x70))
#define STATE(p) (*(int *)((p) + 0x28))
#define TOP(p) (*(char **)(p))

int func_021E5AD4(unsigned char *p)
{
    unsigned r;
    unsigned b, a;

    r = func_02025DE8(LIST(p));
    if (r == (unsigned)-1) {
        if (KEY_GetRepeat() & 0x200) {
            func_021DD238((char *)p);
            r = 2;
        } else if (KEY_GetRepeat() & 0x100) {
            func_021DD238((char *)p);
            r = 3;
        }
    }
    switch (r) {
    case 0:
    case 1:
        func_020260E4(LIST(p), 0);
        if (func_020077B8(*(void **)(TOP(p) + 4), p[0x14]) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            func_021EBC58(p, 0, 4, 0x18);
            STATE(p) = 0x37;
            return 6;
        }
        a = p[0x14];
        b = 0;
        func_020076D0(*(void **)(TOP(p) + 4), (int *)(&a), (int *)(&b));
        *(unsigned char *)(WORK(p) + 0xA17E) = b;
        p[0x1A] = 0;
        p[0x17] = p[0x14];
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return func_021E8F50((char *)p, 0x36);
    case 2:
        func_020260E4(LIST(p), 0);
    case (unsigned)-6:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return func_021E9C94((char *)p, 0, 0x35);
    case 3:
        func_020260E4(LIST(p), 0);
    case (unsigned)-5:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return func_021E9CE0((char *)p, 0, 0x35);
    case 4:
    case (unsigned)-2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        *(unsigned char *)(WORK(p) + 0xA17E) = 0xFF;
        p[0x17] = p[0x14];
        p[0x1A] = 1;
        return func_021E954C(p, 6, 9, func_021E8F50((char *)p, 0x36));
    case (unsigned)-4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case (unsigned)-8:
    case (unsigned)-7:
    case (unsigned)-3:
    case (unsigned)-1:
        break;
    }
    return 0x35;
}
