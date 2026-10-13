/*
 * file:     crc.c
 * unit:     yes
 * function: func_02081940, func_02081980, func_020819B8, func_020819FC, func_02081A40, func_02081A80, func_02081AC0, func_02081B00, func_02081B3C, func_02081B64, func_02081B8C, func_02081BB8
 * address:  0x02081940
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MATHi_CRC8Update  0x02081980  arm
 *   MATHi_CRC16UpdateRev  0x02081A80  arm
 *   MATHi_CRC16Update  0x02081A40  arm
 *   MATHi_CRC32UpdateRev  0x02081B00  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct MATHCRC8Table
{
    u8 table[256];
} MATHCRC8Table;

typedef struct MATHCRC16Table
{
    u16 table[256];
} MATHCRC16Table;

typedef struct MATHCRC32Table
{
    u32 table[256];
} MATHCRC32Table;

extern void MATHi_CRC8Update(MATHCRC8Table *table, u8 *context, void *input, u32 length);
extern void MATHi_CRC16UpdateRev(MATHCRC16Table *table, u16 *context, void *input, u32 length);
extern void MATHi_CRC16Update(MATHCRC16Table *table, u16 *context, void *input, u32 length);
extern void MATHi_CRC32UpdateRev(MATHCRC32Table *table, u32 *context, void *input, u32 length);
void func_02081940(MATHCRC8Table *table, u8 poly);
void func_02081980(MATHCRC8Table *table, u8 *context, void *input, u32 length);
void func_020819B8(MATHCRC16Table *table, u16 poly);
void func_020819FC(MATHCRC16Table *table, u16 poly);
void func_02081A40(MATHCRC16Table *table, u16 *context, void *input, u32 length);
void func_02081A80(MATHCRC16Table *table, u16 *context, void *input, u32 length);
void func_02081AC0(MATHCRC32Table *table, u32 poly);
void func_02081B00(MATHCRC32Table *table, u32 *context, void *input, u32 length);
u8 func_02081B3C(MATHCRC8Table *table, void *data, u32 dataLength);
u16 func_02081B64(MATHCRC16Table *table, void *data, u32 dataLength);
u16 func_02081B8C(MATHCRC16Table *table, void *data, u32 dataLength);
u32 func_02081BB8(MATHCRC32Table *table, void *data, u32 dataLength);


/*
 * sdk:      MATHi_CRC8InitTable (libmath.TWL.HYB.a crc.o)
 *
 *    (none)
 */
void func_02081940(MATHCRC8Table *table, u8 poly)
{
    u32 r, i, j;

    for (i = 0; i < 256; i++)
    {
        r = i;
        for (j = 0; j < 8; j++)
        {
            if (r & 0x80)
            {
                r = (r << 1) ^ poly;
            }
            else
            {
                r <<= 1;
            }
        }
        table->table[i] = (u8)r;
    }
}


/*
 * sdk:      MATHi_CRC8Update (libmath.TWL.HYB.a crc.o)
 *
 *    (none)
 */
void func_02081980(MATHCRC8Table *table, u8 *context, void *input, u32 length)
{
    u32 r, i;
    u8 *data;

    r = *context;
    data = (u8 *)input;
    for (i = 0; i < length; i++)
    {
        r = table->table[(r ^ *data) & 0xFF];
        data++;
    }
    *context = (u8)r;
}


/*
 * sdk:      MATHi_CRC16InitTable (libmath.TWL.HYB.a crc.o)
 *
 *    (none)
 */
void func_020819B8(MATHCRC16Table *table, u16 poly)
{
    u32 r, i, j;

    for (i = 0; i < 256; i++)
    {
        r = i << 8;
        for (j = 0; j < 8; j++)
        {
            if (r & 0x8000)
            {
                r = (r << 1) ^ poly;
            }
            else
            {
                r <<= 1;
            }
        }
        table->table[i] = (u16)r;
    }
}


/*
 * sdk:      MATHi_CRC16InitTableRev (libmath.TWL.HYB.a crc.o)
 *
 *    (none)
 */
void func_020819FC(MATHCRC16Table *table, u16 poly)
{
    u32 r, i, j;

    for (i = 0; i < 256; i++)
    {
        r = i;
        for (j = 0; j < 8; j++)
        {
            if (r & 1)
            {
                r = (r >> 1) ^ poly;
            }
            else
            {
                r >>= 1;
            }
        }
        table->table[i] = (u16)r;
    }
}


/*
 * sdk:      MATHi_CRC16Update (libmath.TWL.HYB.a crc.o)
 *
 *    (none)
 */
void func_02081A40(MATHCRC16Table *table, u16 *context, void *input, u32 length)
{
    u32 r, i;
    u8 *data;

    r = *context;
    data = (u8 *)input;
    for (i = 0; i < length; i++)
    {
        r = (r << 8) ^ table->table[((r >> 8) ^ *data) & 0xFF];
        data++;
    }
    *context = (u16)r;
}


/*
 * sdk:      MATHi_CRC16UpdateRev (libmath.TWL.HYB.a crc.o)
 *
 *    (none)
 */
void func_02081A80(MATHCRC16Table *table, u16 *context, void *input, u32 length)
{
    u32 r, i;
    u8 *data;

    r = *context;
    data = (u8 *)input;
    for (i = 0; i < length; i++)
    {
        r = (r >> 8) ^ table->table[(r ^ *data) & 0xFF];
        data++;
    }
    *context = (u16)r;
}


/*
 * sdk:      MATHi_CRC32InitTableRev (libmath.TWL.HYB.a crc.o)
 *
 *    (none)
 */
void func_02081AC0(MATHCRC32Table *table, u32 poly)
{
    u32 r, i, j;

    for (i = 0; i < 256; i++)
    {
        r = i;
        for (j = 0; j < 8; j++)
        {
            if (r & 1)
            {
                r = (r >> 1) ^ poly;
            }
            else
            {
                r >>= 1;
            }
        }
        table->table[i] = (u32)r;
    }
}


/*
 * sdk:      MATHi_CRC32UpdateRev (libmath.TWL.HYB.a crc.o)
 *
 *    (none)
 */
void func_02081B00(MATHCRC32Table *table, u32 *context, void *input, u32 length)
{
    u32 r, i;
    u8 *data;

    r = *context;
    data = (u8 *)input;
    for (i = 0; i < length; i++)
    {
        r = (r >> 8) ^ table->table[(r ^ *data) & 0xFF];
        data++;
    }
    *context = (u32)r;
}


/*
 * sdk:      MATH_CalcCRC8 (libmath.TWL.HYB.a crc.o)
 */
u8 func_02081B3C(MATHCRC8Table *table, void *data, u32 dataLength)
{
    u8 context = 0;

    MATHi_CRC8Update(table, &context, data, dataLength);
    return context;
}


/*
 * sdk:      MATH_CalcCRC16 (libmath.TWL.HYB.a crc.o)
 */
u16 func_02081B64(MATHCRC16Table *table, void *data, u32 dataLength)
{
    u16 context = 0;

    MATHi_CRC16UpdateRev(table, &context, data, dataLength);
    return context;
}


/*
 * sdk:      MATH_CalcCRC16CCITT (libmath.TWL.HYB.a crc.o)
 */
u16 func_02081B8C(MATHCRC16Table *table, void *data, u32 dataLength)
{
    u16 context = 0xFFFF;

    MATHi_CRC16Update(table, &context, data, dataLength);
    return context;
}


/*
 * sdk:      MATH_CalcCRC32 (libmath.TWL.HYB.a crc.o)
 */
u32 func_02081BB8(MATHCRC32Table *table, void *data, u32 dataLength)
{
    u32 context = ~0;

    MATHi_CRC32UpdateRev(table, &context, data, dataLength);
    return ~context;
}
