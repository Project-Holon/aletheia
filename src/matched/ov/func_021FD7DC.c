/*
 * function: func_021FD7DC
 * address:  0x021FD7DC
 * packet:   pkt_021FD7DC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_021F7FD4  0x021F7FD4  thumb
 *   func_021F8104  0x021F8104  thumb
 *   func_021F886C  0x021F886C  thumb
 *   func_021F8178  0x021F8178  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    s16 name;
    s8 mode;
    s8 key;
    s8 val;
} Rec;

typedef struct {
    void *win;
} Pane;

struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_021F7FD4(void *win, void *bank, u32 index, u32 y, u16 color, void *g);
extern void func_021F8104(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *g);
extern int func_021F886C(int key, int val, int which);
extern void func_021F8178(void *win, void *bank, int idx, u32 e, u32 x, u32 y, u16 color, int alt, u32 g);

void func_021FD7DC(Pane *pane, void *bank, void *names, Rec *rec, void *g)
{
    BMP_Clear(func_02045770(pane->win), 0);
    func_021F7FD4(pane->win, names, rec->name, 0, 0x440, g);
    func_021F8104(pane->win, bank, rec->mode, 0, 0x49, 0, 0x440, g);
    func_021F8178(pane->win, bank, func_021F886C(rec->key, rec->val, 0), 0, 0x68, 0, 0x440, 0, (u32)g);
}
