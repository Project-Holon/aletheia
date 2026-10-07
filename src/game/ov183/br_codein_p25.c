/*
 * file:     br_codein_p25.c
 * unit:     yes
 * function: func_021E19EC, func_021E1BA8, func_021E1C00, func_021E1C14, func_021E1C44
 * address:  0x021E19EC
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E0E40 0x021E0E40 thumb ov183
 *   func_021E1708 0x021E1708 thumb ov183
 *   func_021E1850 0x021E1850 thumb ov183
 *   func_0204B878 0x0204B878 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021FD860 0x021FD860 thumb ov186
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021E11D0 0x021E11D0 thumb ov183
 *   func_021E0E4C 0x021E0E4C thumb ov183
 *   func_021E0E90 0x021E0E90 thumb ov183
 *   func_021E1374 0x021E1374 thumb ov183
 *   func_021E0D00 0x021E0D00 thumb ov183
 */
#include "../../matched/include/Obj00478.h"
#include "../../matched/include/Obj24628.h"

struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {int tag,value,mode,handle; char rest[12];} Record;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021E0E40(int,int);
extern void func_021E1708(char *);
extern void func_021E1850(char *);
extern void func_0204B878(struct Obj *, u16);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020061E4(u32);
extern void func_021FD860(int,int,int *);
extern void func_021E11D0(char *,int);
extern void func_021E0E4C(char *);
extern void func_021E0E90(char *,int);
extern void func_021E1374(char *,int);
extern void func_021E0D00(char *,int);
void func_021E19EC(u32 idx, int arg, char *p);
void func_021E1BA8(char *p);
void func_021E1C00(char *p);
int func_021E1C14(char *p,int a);
int func_021E1C44(const char *p, int a);

/*
 * 2026-10-05 wave P5 lane T5 (pengy share): earlier DIFF, two residues (merged far-branch stubs, idx-12 CSE).
 * 2026-10-05 wave P5 lane T5b: EXACT with the ov129 021D958C forms: idx is u32 (unsigned % and / by plain 5),
 *   `if (*(int *)(p + 0x22C) != 1) return;` then `if (arg == 0) {`, non-const Record pointer. One compile.
 *   Callbacks: func_021E1910 passes this as func_02051B84's callback (idx, arg, obj).
 */
void func_021E19EC(u32 idx, int arg, char *p)
{
    Record *rec = (Record *)p;
    u32 i, j, v;
    int old, val;
    if (*(int *)(p + 0x22C) != 1) return;
    if (arg == 0) {
    if (idx <= 11) {
        if (rec[idx].mode == 1) {
            *(int *)(p + 0x318) = 2;
            *(int *)(p + 0x31C) = idx;
        } else {
            *(int *)(p + 0x318) = 1;
            *(int *)(p + 0x31C) = rec[idx].value;
        }
        func_020061E4(0x703);
        return;
    }
    if (idx == 0x16) {
        u32 x, y;
        int args[2];
        *(u16 *)(p + 0x1B8) = 0;
        *(u16 *)(p + 0x1BA) = 2;
        func_020061E4(0x703);
        func_02035D20(&x, &y);
        args[0] = x;
        args[1] = y;
        func_021FD860(*(int *)(p + 0x348), 1, args);
    } else if (idx == 0x17) {
        u32 x, y;
        int args[2];
        *(u16 *)(p + 0x1B8) = 3;
        *(u16 *)(p + 0x1BA) = 2;
        func_020061E4(0x703);
        func_02035D20(&x, &y);
        args[0] = x;
        args[1] = y;
        func_021FD860(*(int *)(p + 0x348), 1, args);
    } else {
        *(u16 *)(p + 0x1B8) = (idx - 12) % 5;
        *(u16 *)(p + 0x1BA) = (idx - 12) / 5;
        func_020061E4(0x703);
    }
    if (idx >= 12 && idx <= 21) {
        u32 x, y;
        int args[2];
        if (*(int *)(p + 0x240) != 0) {
        func_02035D20(&x, &y);
        args[0] = x;
        args[1] = y;
        func_021FD860(*(int *)(p + 0x348), 1, args);
        i = *(int *)(p + 0x188);
        v = idx - 11;
        func_0204B878((struct Obj *)rec[i].handle, (u16)func_021E0E40(rec[i].tag = v, rec[i].mode));
        old = rec[i].value;
        j = i + 1;
        if (j == *(u32 *)(p + 0x23C)) {
            *(int *)(p + 0x318) = 1;
            *(int *)(p + 0x31C) = 0;
            *(int *)(p + 0x320) = 0;
        } else {
            val = rec[j].value;
            if (old != val) {
                *(int *)(p + 0x318) = 1;
                *(int *)(p + 0x31C) = val;
                *(int *)(p + 0x320) = 0;
            } else {
                *(int *)(p + 0x318) = 2;
                *(int *)(p + 0x31C) = j;
            }
        }
        }
    } else if (idx == 0x16) {
        func_021E1850(p);
    } else {
        func_021E1708(p);
    }
    }
}

/*
 * Extent remainder: zero alignment halfword at 021E1BFE.
 */
void func_021E1BA8(char *p)
{
    switch (((struct Obj00478 *)p)->f318) {
    case 0: break;
    case 1:
        func_021E11D0(p,((struct Obj00478 *)p)->f31C);
        func_021E0E4C(p);
        func_021E0E90(p,1);
        func_021E1374(p,2);
        ((struct Obj00478 *)p)->f318=255;
        break;
    case 2:
        func_021E0D00(p,((struct Obj00478 *)p)->f31C);
        func_021E1C00(p);
        break;
    case 255: break;
    }
}


void func_021E1C00(char *p)
{
    ((struct Obj00478 *)p)->f318 = 0;
    ((struct Obj00478 *)p)->f31C = 0;
    ((struct Obj00478 *)p)->f320 = 0;
}


/*
 * extent: final two bytes are alignment padding.
 */
int func_021E1C14(char *p,int a){int i,n; n=((struct Obj24628 *)p)->f23C;for(i=0;i<n;i++){if(a==*(int *)(p+i*28+4))return i;}return 0;}

/*
 * checks: 1 n/a no calls; 2 matched 1C14 confirms signed index/raw28 stride; 3 enum index DIFF7, unsigned-long count and long index each DIFF4; 4 count/address reuse DIFF4, permuter expands the read-only count field at guard and return; 5 refreshed directory and neighbours; no stack object.
 * matching: re-reading count at guard and return instead of a cached scalar lets the dying offset use r4. No stores or calls can change count during this function.
 * extent: 58 code bytes, alignment padding at021E1C7E..021E1C80; next function starts1C80.
 * retry: 5 one runs, once-only permuter budget300 found expand(n x2) after9 candidates; emitted DIFF4 baseline agrees; winner validated by run6.
 */
int func_021E1C44(const char *p, int a)
{
  int i;
  int found;
  unsigned n;
  n = *((const unsigned *) (p + 0x23c));
  found = 0;
  for (i = 0; i < ((int) (*((const unsigned *) (p + 0x23c)))); i++)
  {
    if (a == (*((const int *) ((p + (i * 28)) + 4))))
      found = 1;
    else
      if (found == 1)
      return i - 1;
  }

  return (*((const unsigned *) (p + 0x23c))) - 1;
}
