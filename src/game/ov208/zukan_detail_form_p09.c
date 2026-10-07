/*
 * file:     zukan_detail_form_p09.c
 * unit:     yes
 * function: func_021C53F4, func_021C5664, func_021C569C, func_021C57A4, func_021C580C, func_021C595C
 * address:  0x021C53F4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BC3C0  0x021BC3C0  thumb
 *   func_021BC3A4  0x021BC3A4  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_0200CC20  0x0200CC20  thumb
 *   func_0200CC40  0x0200CC40  thumb
 *   func_0200D144  0x0200D144  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   data_021C8810  0x021C8810  data
 *   data_021C87FC  0x021C87FC  data
 *   func_0200D288  0x0200D288  thumb
 *   ov208_func_021C5128  0x021C5128  thumb
 *   func_021C80AC  0x021C80AC  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_02015EA0  0x02015EA0  thumb
 *   ov208_func_021C535C  0x021C535C  thumb
 *   func_021C51A0  0x021C51A0  thumb
 *   func_021C51C8  0x021C51C8  thumb
 *   ov208_func_021C5CF0  0x021C5CF0  thumb
 *   ov208_func_021C4BB4  0x021C4BB4  thumb
 *   ov208_func_021C4F30  0x021C4F30  thumb
 *   ov208_func_021C4E54  0x021C4E54  thumb
 *   ov208_func_021C4EAC  0x021C4EAC  thumb
 *   ov208_func_021C6A10  0x021C6A10  thumb
 *   ov208_func_021C6AFC  0x021C6AFC  thumb
 *   ov208_func_021C68D4  0x021C68D4  thumb
 *   func_02014CEC 0x02014CEC thumb
 *   func_021C7534 0x021C7534 thumb ov208
 */
#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
struct Personal;
struct Blk37;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct 
{
  u32 v[3];
} Ov208Gender3;

typedef struct 
{
  u32 v[2];
} Ov208Shiny2;

typedef signed int     fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec;

struct Ov208Mdl {
    u32 obj;
    u32 f4;
    u8  pos[0x3c];
};

struct Ov208Ent {
    u32 kind;
    u32 mode;
    u16 pad8;
    u8  forms;
    u8  padb;
    u16 species;
    u16 pade;
};

struct Ov208Menu {
    u32 owner;
    u8  pad4[0x124];
    u32 arc;
    u32 res[2];
    u32 j;
    u32 k;
    u32 obj[2];
    int cur;
    struct Ov208Ent ents[8];
    u8  pad1c8[0x386];
    u16 sel;
};

extern u16 func_021BC3C0(int key);
extern int func_021BC3A4(int *p);
extern void *func_0200CA1C(void *a);
extern void *func_0201ADE4(u32 a, int b, u32 c);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern u16 func_0200CC20(u32 id);
extern void func_0200CC40(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5);
extern u32 func_0200D144(u8 *p, u16 id, u32 sel, u32 alt, u32 form);
extern u32 func_0200D288(struct Blk37 *p, u32 which);
extern void ov208_func_021C5128(struct Ov208Mdl *m, u32 heap, u32 sys, u32 species, u32 a4,
                                u32 a5, u32 a6, u32 a7, u32 a8, u32 a9);
extern void func_021C80AC(int a, int b, int c);
extern void func_02015C48(void *p, u32 *src);
extern void func_02015EA0(void *p);
extern u32 ov208_func_021C535C(u32 arc, u32 *res, u32 j, u32 k, u32 owner, u16 heap, u32 species,
                               u32 form, u32 gender, u32 isEgg);
extern void func_021C51A0(char *p, int a);
extern void func_021C51C8(u32 obj, int side, u8 *p);
extern void ov208_func_021C5CF0(u16 *heap, u8 *p, int key);
extern void ov208_func_021C4BB4(u16 *heap, u8 *p, int key);
extern void ov208_func_021C4F30(u16 *heap, u8 *p, int key);
extern void ov208_func_021C4E54(u16 *heap, u8 *p, int key);
extern void ov208_func_021C4EAC(u16 *heap, u8 *p, int key);
extern void ov208_func_021C6A10(u16 *heap, u8 *p, int key);
extern void ov208_func_021C6AFC(u16 *heap, u8 *p, int key);
extern void ov208_func_021C68D4(u16 *heap, u8 *p, int key);
extern void func_02014CEC(u8 *p, u32 value);
extern void func_021C7534(u16 *heap, u8 *p, int key);
void ov208_func_021C53F4(u16 *heap, int key, u8 *out, u16 *count, u16 *groups, u16 *twos, u16 *sel, u16 *next);
void ov208_func_021C5664(u16 *heap, u8 *p, int key);
void ov208_func_021C569C(u16 *heap, u8 *p, int key, int a, int b, int pose, u16 idx);
void ov208_func_021C57A4(u16 *heap, struct Ov208Menu *p, int key, u16 idx);
void ov208_func_021C580C(u16 *heap, u8 *p, int key);
void func_021C595C(u16 *heap, u8 *p, int key);
extern const Ov208Gender3 data_021C8810;
extern const Ov208Shiny2 data_021C87FC;

void ov208_func_021C53F4(u16 *heap, int key, u8 *out, u16 *count, u16 *groups, u16 *twos, u16 *sel, u16 *next)
{
  Ov208Gender3 genders = data_021C8810;
  Ov208Shiny2 shinies = data_021C87FC;
  u16 species = func_021BC3C0(key);
  void *pd = func_0200CA1C((void *)func_021BC3A4((int *)key));
  u32 h = (u32)func_0201ADE4(species, 0, *heap);
  u32 ratio;
  u32 forms;
  u32 curGender;
  u32 curShiny;
  u32 curForm;
  u16 cur;
  u16 n = 0;
  u8 j;
  u8 k;
  u32 found;
  u32 g;
  u32 s;
  u8 m;
  u16 prev;
  u32 t;
  u32 i;
  func_0201AE1C((const struct Personal *)h, 0x20);
  ratio = func_0201AE1C((const struct Personal *)h, 0x14);
  func_0201AE14((void *)h);
  forms = func_0200CC20(species);
  func_0200CC40(pd, species, &curGender, &curShiny, &curForm, *heap);
  cur = 0;
  {
    u32 en[3] = {0, 0, 0};
    switch (ratio)
    {
      case 0:
        en[0] = 1;
        break;

      case 0xfe:
        en[1] = 1;
        break;

      case 0xff:
        en[2] = 1;
        break;

      default:
        en[0] = 1;
        en[1] = 1;
        break;

    }

    for (i = 0; i < forms; i++)
    {
      u32 seen[2] = {0, 0};
      for (j = 0; j < 3; j++)
      {
        if (en[j] != 0)
        {
          g = genders.v[j];
          for (k = 0; k < 2; k++)
          {
            found = 0;
            s = shinies.v[k];
            if (((curForm == i) && (curShiny == s)) && (curGender == g))
            {
              cur = n;
              found = 1;
            }
            else
              if ((((forms < 2) || (curForm != i)) || (curShiny != s)) && (func_0200D144(pd, species, g, s, i) != 0))
            {
              found = 1;
            }
            if (found)
            {
              if (((forms >= 2) && (seen[k] == 0)) || (forms < 2))
              {
                seen[k] = 1;
                if (forms >= 2)
                {
                  *((u32 *) (out + (n * 16))) = 2;
                  *((u32 *) ((out + (n * 16)) + 4)) = (s != 0) ? (2) : (1);
                  *((u16 *) ((out + (n * 16)) + 8)) = i;
                }
                else
                {
                  t = 0;
                  if (ratio != 0xff)
                    t = 1;
                  *((u32 *) (out + (n * 16))) = t;
                  *((u32 *) ((out + (n * 16)) + 4)) = (s != 0) ? (2) : (1);
                  *((u16 *) ((out + (n * 16)) + 8)) = (g == 1) ? (1) : (0);
                }
                *((out + (n * 16)) + 10) = g;
                *((out + (n * 16)) + 11) = s;
                *((u16 *) ((out + (n * 16)) + 12)) = i;
                n++;
              }
            }
          }

        }
      }

    }

  }
  *count = n;
  *sel = cur;
  *next = (cur + 1) % n;
  *groups = 0;
  *twos = 0;
  for (m = 0; m < (*count); m++)
  {
    if ((*((u32 *) ((out + (m * 16)) + 4))) == 2)
      (*twos)++;
  }

  for (m = 0; m < (*count); m++)
  {
    if ((*((u32 *) (out + (m * 16)))) == 0)
    {
      *groups = 1;
    }
    else
      if ((m == 0) || (prev != (*((u16 *) ((out + (m * 16)) + 8)))))
    {
      prev = *((u16 *) ((out + (m * 16)) + 8));
      (*groups)++;
    }
  }

}


void ov208_func_021C5664(u16 *heap, u8 *p, int key)
{
    ov208_func_021C53F4(heap, key, p + 0x148, (u16 *)(p + 0x548), (u16 *)(p + 0x54a),
                        (u16 *)(p + 0x54c), (u16 *)(p + 0x54e), (u16 *)(p + 0x550));
}

#define MDL(i) ((struct Ov208Mdl *)(p + 0xc) + (i))


void ov208_func_021C569C(u16 *heap, u8 *p, int key, int a, int b, int pose, u16 idx)
{
    Vec v;
    u16 species;
    u32 form;
    u32 f152;
    u32 f153;
    u32 extra;

    extra = 0;
    species = func_021BC3C0(key);
    form = *(u16 *)(p + idx * 16 + 0x154);
    f152 = *(p + idx * 16 + 0x152);
    f153 = *(p + idx * 16 + 0x153);
    if (species == 0x147)
        extra = func_0200D288(func_0200CA1C((void *)func_021BC3A4((int *)key)), extra);
    if (a != 4) {
        ov208_func_021C5128(MDL(a), *heap, W(8), species, form, f152, f153, 0, 0, extra);
        func_021C80AC((int)MDL(a), pose, (int)(&v));
        func_02015C48((void *)MDL(a)->obj, (u32 *)(&v));
        if (W(0x124) == 0)
            func_02015EA0((void *)MDL(a)->obj);
    }
    if (b != 4) {
        ov208_func_021C5128(MDL(b), *heap, W(8), species, form, f152, f153, 0, 1, extra);
        func_021C80AC((int)MDL(b), pose, (int)(&v));
        func_02015C48((void *)MDL(b)->obj, (u32 *)(&v));
        if (W(0x124) != 0)
            func_02015EA0((void *)MDL(b)->obj);
    }
}


void ov208_func_021C57A4(u16 *heap, struct Ov208Menu *p, int key, u16 idx)
{
    u16 k = func_021BC3C0(key);

    p->obj[p->cur] = ov208_func_021C535C(p->arc, &p->res[p->cur], p->j, p->k, p->owner, *heap, k,
                                         p->ents[idx].species, p->ents[idx].forms, 0);
}

#undef MDL
#define MDL(i) ((struct Ov208Mdl *)(p + 0xc) + (i))


void ov208_func_021C580C(u16 *heap, u8 *p, int key)
{
    u8 i;
    int a;
    int b;
    int pose;

    for (i = 0; i < 4; i++)
        func_021C51A0((char *)MDL(i), W(8));
    ov208_func_021C5664(heap, p, key);
    pose = 0;
    if (W(0x6b8) == 4 && H(0x548) >= 2)
        pose = 1;
    a = W(0x124) != 0 ? 0 : 4;
    b = W(0x124) != 0 ? 4 : 1;
    ov208_func_021C569C(heap, p, key, a, b, pose, H(0x54e));
    if (a != 4)
        func_021C51C8(MDL(0)->f4, 0, p);
    if (b != 4)
        func_021C51C8(MDL(1)->f4, 1, p);
    if (W(0x6b8) == 4 && H(0x548) >= 2) {
        a = W(0x124) != 0 ? 2 : 4;
        b = W(0x124) != 0 ? 4 : 3;
        ov208_func_021C569C(heap, p, key, a, b, 2, H(0x550));
        if (a != 4)
            func_021C51C8(MDL(2)->f4, 2, p);
        if (b != 4)
            func_021C51C8(MDL(3)->f4, 3, p);
    }
    ov208_func_021C5CF0(heap, p, key);
    ov208_func_021C4BB4(heap, p, key);
    ov208_func_021C4F30(heap, p, key);
    ov208_func_021C4E54(heap, p, key);
    ov208_func_021C4EAC(heap, p, key);
    ov208_func_021C6A10(heap, p, key);
    ov208_func_021C6AFC(heap, p, key);
    ov208_func_021C68D4(heap, p, key);
}

#undef MDL
#define MDL(i) ((struct Ov208Mdl *)(p + 0xc + (i) * 0x44))

/*
 * Closed 2026-10-04: pose=0 stays linear via goto skip; models addressed as p + 0xc + i * 0x44.
 */
void func_021C595C(u16 *heap, u8 *p, int key)
{
    Vec v;
    int a;
    int b;
    int pose;
    a = 0;
    func_02014CEC((u8 *)W(8), 0);
    if (MDL(0)->obj != 0) a = 4;
    b = 1;
    if (MDL(1)->obj != 0) b = 4;
    if (W(0x124) != 0) b = 4;
    else a = 4;
    pose = 0;
    if (W(0x6B8) != 4) goto skip;
    if (*(u16 *)(p + 0x548) < 2) goto skip;
    pose = 1;
skip:
    ov208_func_021C569C(heap, p, key, a, b, pose, *(u16 *)(p + 0x54E));
    if (a != 4) func_021C51C8(MDL(0)->f4, 0, p);
    else if (MDL(0)->obj != 0) {
        func_021C80AC((int)MDL(0), pose, (int)(&v));
        func_02015C48((void *)MDL(0)->obj, (u32 *)(&v));
    }
    if (b != 4) func_021C51C8(MDL(1)->f4, 1, p);
    else if (MDL(1)->obj != 0) {
        func_021C80AC((int)MDL(1), pose, (int)(&v));
        func_02015C48((void *)MDL(1)->obj, (u32 *)(&v));
    }
    if (W(0x6B8) == 4 && *(u16 *)(p + 0x548) >= 2) {
        a = 2;
        if (MDL(2)->obj != 0) a = 4;
        b = 3;
        if (MDL(3)->obj != 0) b = 4;
        ov208_func_021C569C(heap, p, key, a, b, 2, *(u16 *)(p + 0x550));
        if (a != 4) func_021C51C8(MDL(2)->f4, 2, p);
        else if (MDL(2)->obj != 0) {
            func_021C80AC((int)MDL(2), 2, (int)(&v));
            func_02015C48((void *)MDL(2)->obj, (u32 *)(&v));
        }
        if (b != 4) func_021C51C8(MDL(3)->f4, 3, p);
        else if (MDL(3)->obj != 0) {
            func_021C80AC((int)MDL(3), 2, (int)(&v));
            func_02015C48((void *)MDL(3)->obj, (u32 *)(&v));
        }
    }
    func_02014CEC((u8 *)W(8), W(0x120));
    if (W(0x6B8) == 0) {
        W(0x6C8) = 1;
        func_021C7534(heap, p, key);
    }
}
