/*
 * file:     unit_02183B60_p02.c
 * unit:     yes
 * function: func_02184470, func_021844E4, func_02184558
 * address:  0x02184470
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02040588 0x02040588 arm
 *   func_0204363C 0x0204363C arm
 *   func_02028604 0x02028604 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021845A4 0x021845A4 thumb ov219
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0208068C 0x0208068C arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_02080B98 0x02080B98 arm
 *   func_020433E0 0x020433E0 arm
 *   d_02185F4C 0x02185F4C data ov219 a4
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02046440 0x02046440 arm
 *   func_0204044C 0x0204044C arm
 *   func_02045088 0x02045088 arm
 *   func_0204361C 0x0204361C arm
 *   d_02185F18 0x02185F18 data ov219 a4
 */
#include "../../matched/include/Obj05564.h"

struct PrintSys;
struct S02031140;
struct S020315D4;
struct WordSet;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef enum {GX_VRAM_NONE=0} GXVRam;

typedef enum {GX_OBJVRAMMODE_CHAR_2D=0,GX_OBJVRAMMODE_CHAR_1D_32K=0x10,GX_OBJVRAMMODE_CHAR_1D_64K=0x100010,GX_OBJVRAMMODE_CHAR_1D_128K=0x200010,GX_OBJVRAMMODE_CHAR_1D_256K=0x300010} GXOBJVRamModeChar;

struct DispVram {GXVRam main_bg,main_bg_expltt,sub_bg,sub_bg_expltt,main_obj,main_obj_expltt,sub_obj,sub_obj_expltt,teximage,texpltt;GXOBJVRamModeChar main_mapping,sub_mapping;};

struct DispConfig {unsigned a,b,c,d;};

extern void func_0201C6EC(struct PrintSys *),func_0201C4C0(struct PrintSys *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0204363C(unsigned);
extern int func_02028604(int);
extern void func_02031140(struct S02031140 *);
extern unsigned func_0201ED04(struct WordSet *);
extern void func_021845A4(int),func_020315D4(struct S020315D4 *),func_020306F0(unsigned int);
extern void func_0208068C(unsigned),func_02082AC0(unsigned,void *,unsigned),func_02080B98(void);
extern void func_020433E0(const struct DispVram *);
extern void func_0203F8F4(unsigned),func_0203FC28(struct DispConfig *);
extern void func_02046440(unsigned,unsigned,unsigned,unsigned,u16,unsigned,void (*)(void));
extern void func_0204044C(unsigned),func_02045088(unsigned),func_0204361C(void);
int func_02184470(struct S020315D4 *controller,void *unused1,void *unused2,char *p);
void func_021844E4(void);
void func_02184558(unsigned heap);
extern const struct DispVram d_02185F4C;
extern const struct DispConfig d_02185F18;

int func_02184470(struct S020315D4 *controller,void *unused1,void *unused2,char *p)
{
    unsigned heap=((struct Obj05564 *)p)->f0;
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj05564 *)p)->fC080);
    func_0201C4C0(*(struct PrintSys * *)&((struct Obj05564 *)p)->fC080);
    func_02040588(6,0);func_02040588(2,0);func_02040588(7,0);func_02040588(3,0);
    func_0204363C(1);
    func_02028604(((struct Obj05564 *)p)->fC088);
    func_02031140(*(struct S02031140 * *)&((struct Obj05564 *)p)->fC0A4);
    func_021845A4(func_0201ED04(*(struct WordSet * *)&((struct Obj05564 *)p)->fC0A8));
    func_020315D4(controller);func_020306F0((u16)heap);
    return 1;
}

/*
 * prototype: 82AC0 SDK asm source reads r0 fill/r1 destination/r2 size;
 * preserve all three observed inputs despite legacy asm void(void).
 */
void func_021844E4(void)
{
    struct DispVram cfg=d_02185F4C;
    func_0208068C(0x1ff);
    func_02082AC0(0,(void *)0x06800000,0xa4000);func_02080B98();
    func_02082AC0(0xc0,(void *)0x07000000,0x400);
    func_02082AC0(0,(void *)0x05000000,0x400);
    func_02082AC0(0xc0,(void *)0x07000400,0x400);
    func_02082AC0(0,(void *)0x05000400,0x400);
    func_020433E0(&cfg);
}

/*
 * prototype: heap forwarded full-width without caller truncation to 3F8F4,
 * 46440 and 45088; widen their legacy narrow parameters accordingly.
 */
void func_02184558(unsigned heap)
{
    struct DispConfig cfg=d_02185F18;
    func_0203F8F4(heap);func_0203FC28(&cfg);
    func_02046440(0,3,0,2,0,heap,0);
    func_0204044C(1);func_02045088(heap);func_0204361C();
}
