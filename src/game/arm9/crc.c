/*
 * file:     crc.c
 * unit:     yes
 * function: MATHi_CRC8InitTable, MATHi_CRC8Update, MATHi_CRC16InitTable, MATHi_CRC16InitTableRev, MATHi_CRC16Update, MATHi_CRC16UpdateRev, MATHi_CRC32InitTableRev, MATHi_CRC32UpdateRev, MATH_CalcCRC8, MATH_CalcCRC16, MATH_CalcCRC16CCITT, MATH_CalcCRC32
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

void MATHi_CRC8InitTable(MATHCRC8Table *table, u8 poly);
void MATHi_CRC8Update(MATHCRC8Table *table, u8 *context, void *input, u32 length);
void MATHi_CRC16InitTable(MATHCRC16Table *table, u16 poly);
void MATHi_CRC16InitTableRev(MATHCRC16Table *table, u16 poly);
void MATHi_CRC16Update(MATHCRC16Table *table, u16 *context, void *input, u32 length);
void MATHi_CRC16UpdateRev(MATHCRC16Table *table, u16 *context, void *input, u32 length);
void MATHi_CRC32InitTableRev(MATHCRC32Table *table, u32 poly);
void MATHi_CRC32UpdateRev(MATHCRC32Table *table, u32 *context, void *input, u32 length);
u8 MATH_CalcCRC8(MATHCRC8Table *table, void *data, u32 dataLength);
u16 MATH_CalcCRC16(MATHCRC16Table *table, void *data, u32 dataLength);
u16 MATH_CalcCRC16CCITT(MATHCRC16Table *table, void *data, u32 dataLength);
u32 MATH_CalcCRC32(MATHCRC32Table *table, void *data, u32 dataLength);


/*
 * sdk:      MATHi_CRC8InitTable (libmath.TWL.HYB.a crc.o)
 *
 *    (none)
 */
void MATHi_CRC8InitTable(MATHCRC8Table *table, u8 poly)
{
    u32 crc, index, bit;

    for (index = 0; index < 256; index++)
    {
        crc = index;
        for (bit = 0; bit < 8; bit++)
        {
            if (crc & 0x80)
            {
                crc = (crc << 1) ^ poly;
            }
            else
            {
                crc <<= 1;
            }
        }
        table->table[index] = (u8)crc;
    }
}


/*
 * sdk:      MATHi_CRC8Update (libmath.TWL.HYB.a crc.o)
 *
 *    (none)
 */
void MATHi_CRC8Update(MATHCRC8Table *table, u8 *context, void *input, u32 length)
{
    u32 crc, index;
    u8 *inputBytes;

    crc = *context;
    inputBytes = (u8 *)input;
    for (index = 0; index < length; index++)
    {
        crc = table->table[(crc ^ *inputBytes) & 0xFF];
        inputBytes++;
    }
    *context = (u8)crc;
}


/*
 * sdk:      MATHi_CRC16InitTable (libmath.TWL.HYB.a crc.o)
 *
 *    (none)
 */
void MATHi_CRC16InitTable(MATHCRC16Table *table, u16 poly)
{
    u32 crc, index, bit;

    for (index = 0; index < 256; index++)
    {
        crc = index << 8;
        for (bit = 0; bit < 8; bit++)
        {
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ poly;
            }
            else
            {
                crc <<= 1;
            }
        }
        table->table[index] = (u16)crc;
    }
}


/*
 * sdk:      MATHi_CRC16InitTableRev (libmath.TWL.HYB.a crc.o)
 *
 *    (none)
 */
void MATHi_CRC16InitTableRev(MATHCRC16Table *table, u16 poly)
{
    u32 crc, index, bit;

    for (index = 0; index < 256; index++)
    {
        crc = index;
        for (bit = 0; bit < 8; bit++)
        {
            if (crc & 1)
            {
                crc = (crc >> 1) ^ poly;
            }
            else
            {
                crc >>= 1;
            }
        }
        table->table[index] = (u16)crc;
    }
}


/*
 * sdk:      MATHi_CRC16Update (libmath.TWL.HYB.a crc.o)
 *
 *    (none)
 */
void MATHi_CRC16Update(MATHCRC16Table *table, u16 *context, void *input, u32 length)
{
    u32 crc, index;
    u8 *inputBytes;

    crc = *context;
    inputBytes = (u8 *)input;
    for (index = 0; index < length; index++)
    {
        crc = (crc << 8) ^ table->table[((crc >> 8) ^ *inputBytes) & 0xFF];
        inputBytes++;
    }
    *context = (u16)crc;
}


/*
 * sdk:      MATHi_CRC16UpdateRev (libmath.TWL.HYB.a crc.o)
 *
 *    (none)
 */
void MATHi_CRC16UpdateRev(MATHCRC16Table *table, u16 *context, void *input, u32 length)
{
    u32 crc, index;
    u8 *inputBytes;

    crc = *context;
    inputBytes = (u8 *)input;
    for (index = 0; index < length; index++)
    {
        crc = (crc >> 8) ^ table->table[(crc ^ *inputBytes) & 0xFF];
        inputBytes++;
    }
    *context = (u16)crc;
}


/*
 * sdk:      MATHi_CRC32InitTableRev (libmath.TWL.HYB.a crc.o)
 *
 *    (none)
 */
void MATHi_CRC32InitTableRev(MATHCRC32Table *table, u32 poly)
{
    u32 crc, index, bit;

    for (index = 0; index < 256; index++)
    {
        crc = index;
        for (bit = 0; bit < 8; bit++)
        {
            if (crc & 1)
            {
                crc = (crc >> 1) ^ poly;
            }
            else
            {
                crc >>= 1;
            }
        }
        table->table[index] = (u32)crc;
    }
}


/*
 * sdk:      MATHi_CRC32UpdateRev (libmath.TWL.HYB.a crc.o)
 *
 *    (none)
 */
void MATHi_CRC32UpdateRev(MATHCRC32Table *table, u32 *context, void *input, u32 length)
{
    u32 crc, index;
    u8 *inputBytes;

    crc = *context;
    inputBytes = (u8 *)input;
    for (index = 0; index < length; index++)
    {
        crc = (crc >> 8) ^ table->table[(crc ^ *inputBytes) & 0xFF];
        inputBytes++;
    }
    *context = (u32)crc;
}


/*
 * sdk:      MATH_CalcCRC8 (libmath.TWL.HYB.a crc.o)
 */
u8 MATH_CalcCRC8(MATHCRC8Table *table, void *data, u32 dataLength)
{
    u8 context = 0;

    MATHi_CRC8Update(table, &context, data, dataLength);
    return context;
}


/*
 * sdk:      MATH_CalcCRC16 (libmath.TWL.HYB.a crc.o)
 */
u16 MATH_CalcCRC16(MATHCRC16Table *table, void *data, u32 dataLength)
{
    u16 context = 0;

    MATHi_CRC16UpdateRev(table, &context, data, dataLength);
    return context;
}


/*
 * sdk:      MATH_CalcCRC16CCITT (libmath.TWL.HYB.a crc.o)
 */
u16 MATH_CalcCRC16CCITT(MATHCRC16Table *table, void *data, u32 dataLength)
{
    u16 context = 0xFFFF;

    MATHi_CRC16Update(table, &context, data, dataLength);
    return context;
}


/*
 * sdk:      MATH_CalcCRC32 (libmath.TWL.HYB.a crc.o)
 */
u32 MATH_CalcCRC32(MATHCRC32Table *table, void *data, u32 dataLength)
{
    u32 context = ~0;

    MATHi_CRC32UpdateRev(table, &context, data, dataLength);
    return ~context;
}
