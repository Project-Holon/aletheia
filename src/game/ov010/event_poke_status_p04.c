/*
 * file:     event_poke_status_p04.c
 * unit:     yes
 * function: func_0215948C, func_021594B0
 * address:  0x0215948C
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
 *   func_02011398  0x02011398  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_0201137C  0x0201137C  thumb
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_020142E8  0x020142E8  thumb
 */
struct Ring;
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

extern u32 func_02011398(struct Ring *r);
extern int func_0209C2B0();
extern int func_0201137C();
extern void *func_0215A5E4(void *a0);
extern u32 func_0201296C(const struct BigObj *p);
extern unsigned int func_02159B10(void *, void *);
extern u32 func_020142E8(void *bitmap, s32 id);
int func_0215948C(int a0, int a1);
int func_021594B0(int a0, int a1);


int func_0215948C(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = func_02011398((struct Ring *)a0);
loc_02159494:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02011398((struct Ring *)a0);
loc_0215949C:
a1 = t4 + 0;
    a0 = func_0209C2B0(a0, a1);
loc_021594A2:
a1 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0201137C(a0, a1);
loc_021594AA:
a0 = 0;
    return a0;}


int func_021594B0(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_021594BC:
    a0 = func_0201296C(v0);
loc_021594C0:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_021594CA:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_020142E8((void *)a0, a1);
loc_021594D2:
a1 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0201137C(a0, a1);
loc_021594DA:
a0 = 0;
    return a0;}
