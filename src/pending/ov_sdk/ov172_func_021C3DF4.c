/*
 * function: func_021C3DF4
 * address:  0x021C3DF4
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * SDK provenance (read from sdk/TwlSDK/lib/ARM9-TS/{Release,Rom}/libssp.TWL.HYB.a
 * (exifenc.o), whose jpeg_encode_main is byte-identical to this ROM function
 * apart from relocations):
 *   short jpeg_encode_main(short width, short height, unsigned short encode_option,
 *                          unsigned char *thumb_src, unsigned long thumb_size);
 *   locals: short cfg_encode_exif, cfg_encode_gray_scale, cfg_input_width,
 *           cfg_input_height; jpeg_exif_data_structure *jexif; exif_tag_entry *entry;
 * The source builds 27 ifd tag entries (each a block declaring its own `entry`)
 * and then, when cfg_encode_exif is set, appends the ExifIFD/interop/jpeg
 * pointers.  Structs recovered from the object's DWARF:
 *   exif_tag_entry{tag,type,count,byte_data,padding,short_data,long_data,
 *     rational_data[2],undefined_data[30],ascii_data[30],offset} = 0x58
 *   exif_ifd_data{entries,count,padding,next_ifd_pointer} = 0x0C
 *   jpeg_exif_data_structure{ifd[5],app1_length,thumb_compressed_data,
 *     thumb_compressed_length} = 0x48
 *
 * Divergence (blocker): size-exact at 3496 bytes and all 31 relocation sites now
 * resolve (write_exif_ifd_tables added to symbols: and the contested ov172 token
 * dropped from g_021CB728/g_021CAE90), but 279 concrete bytes over 122
 * instructions in 10 clusters still differ, all of them register assignment.
 * First order difference is +0x204:
 *   image ldrsh r1,[sb,#4] / add r1,r1,#1 / strh r1,[sb,#4] / ldr r1,[pc] / ldr r1,[r1,#0xc] / cmp
 *   ours  ldr r1,[pc] / ldrsh r2,[sb,#4] / ldr r1,[r1,#0xc] / cmp / add r1,r2,#1 / strh r1,[sb,#4]
 * i.e. the original keeps the tag-3 count0++ together ahead of the
 * g_021CADF0.fieldC test while ours interleaves the pool load into it and has
 * to keep the counter in r2.  Every later cluster is a rotation of the same
 * register set (r0/r1/sl/fp/r3) inside the 27 per-tag `entry` blocks.
 * `-O4,p` is the only flag set that is close (all seven pins D279; -O4/-O4,s
 * D2634, -O2 D2593), so pin and flags are not the lever.
 * Fixed this lane: tag 0x0213 short_data was 1, the image's literal at
 * 0x021C4B6C is 0x00000213 and it stores r7 (loaded as 2 at 0x021C4088), so
 * `s->fieldA` is 2 (verified).  Next lever: recover exifenc.c verbatim or find
 * the source form that keeps the tag-3 counter in r1.
 *
 * symbols:
 *   g_021CAE48 0x021CAE48 data ov172
 *   g_021CB728 0x021CB728 data
 *   g_021CC070 0x021CC070 data ov172
 *   g_021CAEE8 0x021CAEE8 data ov172
 *   g_021CB308 0x021CB308 data ov172
 *   g_021CBBA0 0x021CBBA0 data ov172
 *   g_021C8894 0x021C8894 data ov172
 *   g_021C88A0 0x021C88A0 data ov172
 *   g_021CADF0 0x021CADF0 data ov172
 *   g_021CAE28 0x021CAE28 data ov172
 *   g_021CAE14 0x021CAE14 data ov172
 *   g_021C88AC 0x021C88AC data ov172
 *   g_021C88B4 0x021C88B4 data ov172
 *   g_021CAE90 0x021CAE90 data
 *   g_021CAEC6 0x021CAEC6 data ov172
 *   g_021C88BC 0x021C88BC data ov172
 *   g_021C88C0 0x021C88C0 data ov172
 *   write_exif_ifd_tables 0x021C3A28 arm ov172
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
struct Slot
{
  u16 tag;
  u16 type;
  u32 count;
  s8 field8;
  u8 pad9;
  s16 fieldA;
  u32 fieldC;
  u32 field10;
  u32 field14;
  u8 field18[30];
  char str[30];
  u32 field54;
};
struct SlotManager
{
  struct Slot *ptr0;
  s16 count0;
  u16 pad6;
  u32 field8;
  struct Slot *ptrC;
  s16 count1;
  u16 pad12;
  u32 field14;
  struct Slot *ptr18;
  s16 count2;
  u16 pad1E;
  u32 field20;
  struct Slot *ptr24;
  s16 count3;
  u16 pad2A;
  u32 field2C;
  struct Slot *ptr30;
  s16 count4;
  u16 pad36;
  u32 field38;
  u32 pad3C[2];
  u32 field44;
};
struct UnkObj
{
  u32 field0;
  u32 len;
  u32 field8;
  u32 fieldC;
  u32 field10;
  u8 *buffer;
  u32 field18;
};
extern struct SlotManager g_021CAE48;
extern struct Slot g_021CB728[];
extern struct Slot g_021CC070[];
extern struct Slot g_021CAEE8[];
extern struct Slot g_021CB308[];
extern struct Slot g_021CBBA0[];
extern const char g_021C8894[];
extern const char g_021C88A0[];
extern struct UnkObj g_021CADF0;
extern const char g_021CAE28[];
extern const char g_021CAE14[];
extern const char g_021C88AC[];
extern const char g_021C88B4[];
extern struct Slot g_021CAE90;
extern const char g_021CAEC6[];
extern const char g_021C88BC[];
extern const char g_021C88C0[];
extern void STD_CopyLString(char *dst, const char *src, u32 n);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
extern u32 write_exif_ifd_tables(struct SlotManager *mgr, u32 mode, u8 *thumb_src, u32 thumb_size);
s16 func_021C3DF4(s16 width, s16 height, u16 encode_option, u8 *thumb_src, u32 thumb_size)
{
  s16 cfg_encode_exif;
  s16 cfg_encode_gray_scale;
  s16 cfg_input_width;
  s16 cfg_input_height;
  struct SlotManager *sb = &g_021CAE48;
  struct Slot *s;
  s16 cfg_encode_exif_;
  u32 tmp;
  sb->ptr0 = g_021CB728;
  sb->count0 = 0;
  sb->field8 = 0;
  sb->ptrC = g_021CC070;
  sb->count1 = 0;
  sb->field14 = 0;
  sb->ptr18 = g_021CAEE8;
  sb->count2 = 0;
  sb->field20 = 0;
  sb->ptr24 = g_021CB308;
  sb->count3 = 0;
  sb->field2C = 0;
  sb->ptr30 = g_021CBBA0;
  sb->count4 = 0;
  sb->field38 = 0;
  if (encode_option & 1)
  {
    cfg_encode_exif = 1;
  }
  else
  {
    cfg_encode_exif = 0;
  }
  cfg_encode_gray_scale = 0;
  cfg_input_width = width;
  cfg_input_height = height;
  sb->count0 = 0;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x010F;
  s->type = 2;
  s->count = 9;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  STD_CopyLString(s->str, g_021C8894, 9);
  s->field54 = 0;
  sb->count0++;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x0110;
  s->type = 2;
  s->count = 11;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_0208CB10(s->str, g_021C88A0, 11);
  s->field54 = 0;
  sb->count0++;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x011A;
  s->type = 5;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 72;
  s->field14 = 1;
  s->field54 = 0;
  sb->count0++;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x011B;
  s->type = 5;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 72;
  s->field14 = 1;
  s->field54 = 0;
  sb->count0++;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x0128;
  s->type = 3;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 2;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count0++;
  if (g_021CADF0.fieldC != 0)
  {
    s = &sb->ptr0[sb->count0];
    s->tag = 0x0131;
    s->type = 2;
    s->count = g_021CADF0.fieldC;
    s->field8 = 0;
    s->fieldA = 0;
    s->fieldC = 0;
    s->field10 = 0;
    s->field14 = 0;
    func_0208CB10(s->str, g_021CAE28, s->count);
    s->field54 = 0;
    sb->count0++;
  }
  s = &sb->ptr0[sb->count0];
  s->tag = 0x0132;
  s->type = 2;
  s->count = 20;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_0208CB10(s->str, g_021CAE14, 20);
  s->field54 = 0;
  sb->count0++;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x0213;
  s->type = 3;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 2;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count0++;
  sb->count1 = 0;
  s = &sb->ptrC[sb->count1];
  s->tag = 0x9000;
  s->type = 7;
  s->count = 4;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_02082EA4(g_021C88AC, s->field18, 4);
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0x9003;
  s->type = 2;
  s->count = 20;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_0208CB10(s->str, g_021CAE14, 20);
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0x9004;
  s->type = 2;
  s->count = 20;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_0208CB10(s->str, g_021CAE14, 20);
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0x9101;
  s->type = 7;
  s->count = 4;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field18[0] = 1;
  s->field18[1] = 2;
  s->field18[2] = 3;
  s->field18[3] = 0;
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0x927C;
  s->type = 7;
  s->count = 0;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field18[0] = 1;
  s->field18[1] = 2;
  s->field18[2] = 3;
  s->field18[3] = 0;
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0xA000;
  s->type = 7;
  s->count = 4;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_02082EA4(s->field18, g_021C88B4, 4);
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0xA001;
  s->type = 3;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 1;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  tmp = sb->count1;
  sb->count1++;
  s = &sb->ptrC[tmp];
  s->tag = 0xA002;
  s->type = 4;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = (u32) cfg_input_width;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0xA003;
  s->type = 4;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = (u32) cfg_input_height;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count2 = 0;
  sb->count1++;
  s = &sb->ptr18[sb->count2];
  s->tag = g_021CAE90.tag;
  s->type = g_021CAE90.type;
  s->count = g_021CAE90.count;
  s->field8 = g_021CAE90.field8;
  s->fieldA = g_021CAE90.fieldA;
  s->fieldC = g_021CAE90.fieldC;
  s->field10 = g_021CAE90.field10;
  s->field14 = g_021CAE90.field14;
  func_0208CB10(s->str, g_021CAEC6, 0);
  s->field54 = 0;
  sb->count2++;
  if (g_021CADF0.field18 != 0)
  {
    s = &sb->ptr18[sb->count2];
    s->tag = 0x1001;
    s->type = 7;
    s->count = g_021CADF0.field18;
    s->field8 = 0;
    s->fieldA = 0;
    s->fieldC = 0;
    s->field10 = 0;
    s->field14 = 0;
    s->field54 = 0;
    sb->count2++;
  }
  if (g_021CADF0.field10 != 0)
  {
    s = &sb->ptr18[sb->count2];
    s->tag = 0x1002;
    s->type = 7;
    s->count = g_021CADF0.field10;
    s->field8 = 0;
    s->fieldA = 0;
    s->fieldC = 0;
    s->field10 = 0;
    s->field14 = 0;
    s->field54 = 0;
    sb->count2++;
  }
  sb->count3 = 0;
  s = &sb->ptr24[sb->count3];
  s->tag = 0x0001;
  s->type = 2;
  s->count = 4;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_0208CB10(s->str, g_021C88BC, 4);
  s->field54 = 0;
  sb->count3++;
  s = &sb->ptr24[sb->count3];
  s->tag = 0x0002;
  s->type = 7;
  s->count = 4;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_02082EA4(s->field18, g_021C88B4, 4);
  s->field54 = 0;
  sb->count3++;
  s = &sb->ptr24[sb->count3];
  s->tag = 0x1000;
  s->type = 2;
  s->count = 18;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_0208CB10(s->str, g_021C88C0, 18);
  s->field54 = 0;
  sb->count4 = 0;
  sb->count3++;
  s = &sb->ptr30[sb->count4];
  s->tag = 0x0103;
  s->type = 3;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 6;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count4++;
  s = &sb->ptr30[sb->count4];
  s->tag = 0x011A;
  s->type = 5;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 72;
  s->field14 = 1;
  s->field54 = 0;
  sb->count4++;
  s = &sb->ptr30[sb->count4];
  s->tag = 0x011B;
  s->type = 5;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 72;
  s->field14 = 1;
  s->field54 = 0;
  sb->count4++;
  s = &sb->ptr30[sb->count4];
  s->tag = 0x0128;
  s->type = 3;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 2;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  cfg_encode_exif_ = cfg_encode_exif;
  sb->count4++;
  if (cfg_encode_exif_)
  {
    if (sb->count0 == 0)
    {
      return 0;
    }
    s = &sb->ptr0[sb->count0];
    s->tag = 0x8769;
    s->type = 4;
    s->count = 1;
    sb->count0++;
    if (sb->count2 != 0)
    {
      if (((g_021CAE90.count + g_021CADF0.field18) + g_021CADF0.field10) != 0)
      {
        struct Slot *m = &sb->ptrC[4];
        m->tag = 0x927C;
        m->type = 7;
        m->count = 6;
        if (g_021CAE90.count != 0)
        {
          m->count += 12;
        }
        if (g_021CADF0.field18 != 0)
        {
          m->count += 12;
        }
        if (g_021CADF0.field10 != 0)
        {
          m->count += 12;
        }
        m->count = ((g_021CAE90.count + g_021CADF0.field18) + g_021CADF0.field10) + m->count;
      }
    }
    if (sb->count3 != 0)
    {
      s = &sb->ptrC[sb->count1];
      s->tag = 0xA005;
      s->type = 4;
      s->count = 1;
      sb->count1++;
    }
    s = &sb->ptr30[sb->count4];
    s->tag = 0x0201;
    s->type = 4;
    s->count = 1;
    sb->count4++;
    s = &sb->ptr30[sb->count4];
    s->tag = 0x0202;
    s->type = 4;
    s->count = 1;
    sb->field44 = (u32) thumb_size;
    sb->count4++;
  }
  else
  {
    if (sb->count0 == 0)
    {
      return 0;
    }
    s = &sb->ptr0[sb->count0];
    s->tag = 0x8769;
    s->type = 4;
    s->count = 1;
    sb->count0++;
    if (sb->count2 != 0)
    {
      if (((g_021CADF0.field18 + g_021CAE90.count) + g_021CADF0.field10) != 0)
      {
        struct Slot *m = &sb->ptrC[4];
        m->tag = 0x927C;
        m->type = 7;
        m->count = 6;
        if (g_021CAE90.count != 0)
        {
          m->count += 12;
        }
        if (g_021CADF0.field18 != 0)
        {
          m->count += 12;
        }
        if (g_021CADF0.field10 != 0)
        {
          m->count += 12;
        }
        m->count = ((g_021CAE90.count + g_021CADF0.field18) + g_021CADF0.field10) + m->count;
      }
    }
    if (sb->count3 != 0)
    {
      s = &sb->ptrC[sb->count1];
      s->tag = 0xA005;
      s->type = 4;
      s->count = 1;
      sb->count1++;
    }
    s = &sb->ptr30[sb->count4];
    s->tag = 0x0201;
    s->type = 4;
    s->count = 1;
    sb->count4++;
    s = &sb->ptr30[sb->count4];
    s->tag = 0x0202;
    s->type = 4;
    s->count = 1;
    sb->field44 = 0;
    sb->count4++;
  }
  g_021CADF0.buffer[g_021CADF0.len++] = 0xFF;
  g_021CADF0.buffer[g_021CADF0.len++] = 0xD8;
  if (cfg_encode_exif_)
  {
    if (write_exif_ifd_tables(sb, 0, thumb_src, thumb_size) == 0)
    {
      return 0;
    }
  }
  else
  {
    if (write_exif_ifd_tables(sb, 1, thumb_src, thumb_size) == 0)
    {
      return 0;
    }
  }
  if ((g_021CADF0.len & 1) == 1)
  {
    g_021CADF0.buffer[g_021CADF0.len++] = 0;
  }
  return 1;
}
