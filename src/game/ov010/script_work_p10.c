/*
 * file:     script_work_p10.c
 * unit:     yes
 * function: func_02158AC8, func_02158AD4, func_02158AE0, func_02158B00
 * address:  0x02158AC8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02158A90  0x02158A90  thumb
 *   func_020120F4   0x020120F4  thumb
 *   func_0201296C   0x0201296C  thumb
 *   func_021589F4   0x021589F4  thumb  ov010
 *   func_02012844 0x02012844 thumb
 *   func_02162450 0x02162450 thumb ov010
 *   func_02158B6C 0x02158B6C thumb ov010
 *   func_02158768 0x02158768 thumb ov010
 */
struct BigObj;
struct Ctx;
struct Desc;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

int func_02158A90(void *a, int unused, int key, int d);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern int func_021589F4(int a0);
extern u32 func_02012844(const struct BigObj *p);
extern u32 func_02162450(void *p);
extern u16 func_02158B6C(const void *a, const u8 *list, u32 key);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
void func_02158AC8(int a, int b);
void func_02158AD4(int a, int b);
void func_02158AE0(void *a0, void *a1);
void *func_02158B00(void *a, u32 b);


void func_02158AC8(int a, int b)
{
    func_02158A90((void *)a, b, 4, 1);
}


void func_02158AD4(int a, int b)
{
    func_02158A90((void *)a, b, 3, 1);
}


/*
 * Two arm9 frame calls, an overlay reset, then the four-argument submit.
 */
void func_02158AE0(void *a0, void *a1)
{
    func_021589F4(func_0201296C(func_020120F4(a0)));
    func_02158A90(a0, (int)a1, 2, 2);
}

void *func_02158B00(void *a, u32 b) {
    void *s = func_020120F4(a);
    int msg = func_02158B6C(s, (const u8 *)func_02162450((void *)func_02012844(s)), 1);
    if (msg == 0xffff) return 0;
    return func_02158768((int)a, msg, 0, b);
}
