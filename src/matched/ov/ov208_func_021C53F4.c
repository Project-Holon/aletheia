/*
 * function: ov208_func_021C53F4
 * address:  0x021C53F4
 * packet:   pkt_ov208_021C53F4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: 2026-10-05 (wD7 lane16): EXACT. species is a u16 local and func_0200CC40/func_0200D144 take a
 *   u16 id (as their other matched callers declare); the species reload then follows the argument order.
 * symbols:
 *   func_021BC3C0  0x021BC3C0  thumb
 *   func_021BC3A4  0x021BC3A4  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   func_0200CC20  0x0200CC20  thumb
 *   func_0200CC40  0x0200CC40  thumb
 *   func_0200D144  0x0200D144  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   data_021C8810  0x021C8810  data
 *   data_021C87FC  0x021C87FC  data
 */
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
extern u16 func_021BC3C0(int key);
struct Personal;
extern int func_021BC3A4(int *p);
extern void *func_0200CA1C(void *a);
extern void *POKE_PERSONAL_Create(u32 a, int b, u32 c);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);
extern u16 func_0200CC20(u32 id);
extern void func_0200CC40(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5);
extern u32 func_0200D144(u8 *p, u16 id, u32 sel, u32 alt, u32 form);
extern const Ov208Gender3 data_021C8810;
extern const Ov208Shiny2 data_021C87FC;
void ov208_func_021C53F4(u16 *heap, int key, u8 *out, u16 *count, u16 *groups, u16 *twos, u16 *sel, u16 *next)
{
  Ov208Gender3 genders = data_021C8810;
  Ov208Shiny2 shinies = data_021C87FC;
  u16 species = func_021BC3C0(key);
  void *pd = func_0200CA1C((void *)func_021BC3A4((int *)key));
  u32 h = (u32)POKE_PERSONAL_Create(species, 0, *heap);
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
  POKE_PERSONAL_GetParam((const struct Personal *)h, 0x20);
  ratio = POKE_PERSONAL_GetParam((const struct Personal *)h, 0x14);
  POKE_PERSONAL_Delete((void *)h);
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


