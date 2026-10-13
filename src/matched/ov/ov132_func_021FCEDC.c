/*
 * function: func_021FCEDC
 * address: 0x021FCEDC
 * packet: pkt_ov132_021FCEDC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: bounded permuter introduced full-word row-address temporaries with split assignments in case 12; every temporary is assigned before reading, indices retain the explicit u8 extraction.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   d_021FDE5C 0x021FDE5C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern const char d_021FDE5C[];
typedef struct 
{
  u8 tag;
  u32 data;
} Packet;
void func_021FCEDC(unsigned long slot, int unused, const Packet *q, char *p)
{
  u8 i;
  u8 t;
  u8 code;
  u8 index;
  u8 item;
  u32 mask;
  u32 v;
  u32 tmp;
  u32 tmp1;
  switch (q->tag)
  {
    case 0:
      *((u32 *) (p + 0x18)) = 1;
      break;

    case 1:
      mask = 15;
      for (i = 0; i < 4; i++)
    {
      *((u8 *) ((p + (i * 0x30)) + 0x72)) = (q->data & mask) >> (i * 4);
      mask <<= 4;
    }

      break;

    case 2:
      *((u32 *) ((p + (slot * 0x30)) + 0x78)) = q->data;
      if ((*((u32 *) (p + 0x48))) == 1)
      *((u32 *) (p + 0x184)) = 1;
      break;

    case 3:
      if ((*((u32 *) (p + 0x48))) != 1)
    {
      v = q->data;
      *((u32 *) (p + 0x78)) = v & 15;
      *((u32 *) (p + 0xa8)) = (v & 0xf0) >> 4;
      *((u32 *) (p + 0xd8)) = (v & 0xf00) >> 8;
      *((u32 *) (p + 0x108)) = (v & 0xf000) >> 12;
    }
      break;

    case 4:
      if ((*((u32 *) (p + 0x48))) == 2)
    {
      *((void **) ((*((char **) (p + 0x140))) + 4)) = func_02030734(4, q->data, 0, d_021FDE5C, 0x4c4);
      *((u32 *) ((*((char **) (p + 0x140))) + 0x20)) = q->data;
    }
      *((u32 *) (p + 0x164)) = 1;
      break;

    case 5:
      if ((*((u32 *) (p + 0x48))) == 2)
    {
      *((void **) ((*((char **) (p + 0x140))) + 8)) = func_02030734(44, q->data, 0, d_021FDE5C, 0x4cd);
      *((u32 *) ((*((char **) (p + 0x140))) + 0x24)) = q->data;
    }
      *((u32 *) (p + 0x168)) = 1;
      break;

    case 6:
      if ((*((u32 *) (p + 0x48))) == 2)
    {
      *((void **) ((*((char **) (p + 0x140))) + 12)) = func_02030734(44, q->data, 0, d_021FDE5C, 0x4d6);
      *((u32 *) ((*((char **) (p + 0x140))) + 0x28)) = q->data;
    }
      *((u32 *) (p + 0x16c)) = 1;
      break;

    case 7:
      if ((*((u32 *) (p + 0x48))) == 1)
      *((u32 *) (p + 0x17c)) = 3;
    else
    {
      *((void **) ((*((char **) (0x140 + p))) + 16)) = func_02030734(44, q->data, 0, d_021FDE5C, 0x4e3);
      *((u32 *) ((*((char **) (p + 0x140))) + 0x2c)) = q->data;
    }
      break;

    case 8:
      *((u32 *) (p + 0x144)) = q->data;
      break;

    case 9:
      *((u32 *) (p + 0x148)) = q->data;
      break;

    case 10:
      if ((*((u32 *) (p + 0x48))) == 1)
    {
      *((u32 *) ((((u32) p) + (slot * 0x30)) + 0x6c)) = 1;
      *((u8 *) ((p + (slot * 0x30)) + 0x70)) = q->data;
    }
      break;

    case 11:
    {
      u8 t;
      u8 i;
      u32 mask;
      mask = 15;
      for (i = 0; i < 4; i++)
      {
        t = (q->data & mask) >> (i * 4);
        if (t != 10)
          *((u8 *) ((p + (i * 0x30)) + 0x71)) = t;
        mask <<= 4;
      }

      *((u8 *) (p + 0x180)) = (q->data & 0xf0000) >> 16;
      break;
    }

    case 12:
    {
      u8 i;
      int code;
      int item;
      u16 index;
      u32 v;
      v = q->data;
      code = (u8) ((v & 0xff0000) >> 16);
      index = (u8) ((v & 0xff00) >> 8);
      item = (u8) v;
      for (i = 0; i < 2; i++)
      {
        tmp1 = ((u32) p) + (index * 0x30);
        tmp1 = tmp1 + i;
        if ((*((u8 *) (tmp1 + 0x73))) == 255)
        {
          tmp = (u32) p;
          tmp = tmp + (index * 0x30);
          *((u8 *) ((tmp + i) + 0x73)) = item;
          break;
        }
      }

      if (code == 1)
        GFL_USE_PlaySeDefaultVolume(0x62c);
      else
        if (code == 2)
        GFL_USE_PlaySeDefaultVolume(0x62b);
      break;
    }

  }

}
