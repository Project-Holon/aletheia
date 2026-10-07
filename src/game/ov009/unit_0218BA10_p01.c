/*
 * file:     unit_0218BA10_p01.c
 * unit:     yes
 * function: func_0218BA10, func_0218BB70, func_0218BBDC
 * address:  0x0218BA10
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02193734  0x02193734  arm   ov009
 *   g_021A4A98     0x021A4A98  data  ov009
 *   func_0219327C  0x0219327C  arm   ov009
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct GPIInfoCache {
    char *nick;
    char *uniquenick;
    char *email;
    char *firstname;
    char *lastname;
    char *homepage;
    int icquin;
    char zipcode[11];
    char countrycode[3];
    float longitude;
    float latitude;
    char place[128];
    int birthday;
    int birthmonth;
    int birthyear;
    int sex;
    int publicmask;
    char *aimname;
    int pic;
    int occupationid;
    int industryid;
    int incomeid;
    int marriedid;
    int childcount;
    int interests1;
    int ownership1;
    int conntypeid;
} GPIInfoCache;

typedef struct GPGetInfoResponseArg {
    int result;
    int profile;
    char nick[31];
    char uniquenick[21];
    char email[51];
    char firstname[31];
    char lastname[31];
    char homepage[76];
    int icquin;
    char zipcode[11];
    char countrycode[3];
    float longitude;
    float latitude;
    char place[128];
    int birthday;
    int birthmonth;
    int birthyear;
    int sex;
    int publicmask;
    char aimname[51];
    int pic;
    int occupationid;
    int industryid;
    int incomeid;
    int marriedid;
    int childcount;
    int interests1;
    int ownership1;
    int conntypeid;
} GPGetInfoResponseArg;

extern void func_02193734(int *p, int b);
extern void func_0219327C(char *p, int b, int n);
int func_0218BA10(int day, int month, int year);
int func_0218BB70(void **connection, int date, int *day, int *month, int *year);
void func_0218BBDC(GPIInfoCache *cache, GPGetInfoResponseArg *arg);
extern char g_021A4A98[];


/*
 * Date validity (day, month, year): all-zero is accepted, negatives rejected,
 * month dispatch with February leap handling, then a 1900..2079 window with a
 * 2079-07-06 upper cutoff.
 */
int func_0218BA10(int day, int month, int year)
{
    if (day == 0 && month == 0 && year == 0)
        return 1;
    if (day < 0 || month < 0 || year < 0)
        return 0;
    switch (month) {
    case 0:
        if (day != 0)
            return 0;
        break;
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        if (day > 31)
            return 0;
        break;
    case 4: case 6: case 9: case 11:
        if (day > 30)
            return 0;
        break;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            if (day > 29)
                return 0;
        } else {
            if (day > 28)
                return 0;
        }
        break;
    default:
        return 0;
    }
    if (year < 1900)
        return 0;
    if (year > 2079)
        return 0;
    if (year == 2079) {
        if (month > 6)
            return 0;
        if (month == 6 && day > 6)
            return 0;
    }
    return 1;
}


/*
 * sdk:      gpiIntToDate (gpiinfo.o)
 */
int func_0218BB70(void **connection, int date, int *day, int *month, int *year)
{
    int d;
    int m;
    int y;

    d = (date >> 24) & 0xFF;
    m = (date >> 16) & 0xFF;
    y = date & 0xFFFF;
    if (!func_0218BA10(d, m, y)) {
        func_02193734((int *)connection, (int)g_021A4A98);
        return 2;
    }
    *day = d;
    *month = m;
    *year = y;
    return 0;
}


/*
 * sdk:      gpiInfoCacheToArg (gpiinfo.o)
 */
void func_0218BBDC(GPIInfoCache *cache, GPGetInfoResponseArg *arg)
{
    if (cache->nick)
        func_0219327C(arg->nick, (int)cache->nick, 31);
    else
        arg->nick[0] = '\0';
    if (cache->uniquenick)
        func_0219327C(arg->uniquenick, (int)cache->uniquenick, 21);
    else
        arg->uniquenick[0] = '\0';
    if (cache->email)
        func_0219327C(arg->email, (int)cache->email, 51);
    else
        arg->email[0] = '\0';
    if (cache->firstname)
        func_0219327C(arg->firstname, (int)cache->firstname, 31);
    else
        arg->firstname[0] = '\0';
    if (cache->lastname)
        func_0219327C(arg->lastname, (int)cache->lastname, 31);
    else
        arg->lastname[0] = '\0';
    if (cache->homepage)
        func_0219327C(arg->homepage, (int)cache->homepage, 76);
    else
        arg->homepage[0] = '\0';
    arg->icquin = cache->icquin;
    func_0219327C(arg->zipcode, (int)cache->zipcode, 11);
    func_0219327C(arg->countrycode, (int)cache->countrycode, 3);
    arg->longitude = cache->longitude;
    arg->latitude = cache->latitude;
    if (cache->place)
        func_0219327C(arg->place, (int)cache->place, 128);
    else
        arg->place[0] = '\0';
    arg->birthday = cache->birthday;
    arg->birthmonth = cache->birthmonth;
    arg->birthyear = cache->birthyear;
    arg->sex = cache->sex;
    arg->publicmask = cache->publicmask;
    if (cache->aimname)
        func_0219327C(arg->aimname, (int)cache->aimname, 51);
    else
        arg->aimname[0] = '\0';
    arg->icquin = cache->icquin;
    arg->longitude = cache->longitude;
    arg->latitude = cache->latitude;
    arg->birthday = cache->birthday;
    arg->birthmonth = cache->birthmonth;
    arg->birthyear = cache->birthyear;
    arg->sex = cache->sex;
    arg->publicmask = cache->publicmask;
    arg->pic = cache->pic;
    arg->occupationid = cache->occupationid;
    arg->industryid = cache->industryid;
    arg->incomeid = cache->incomeid;
    arg->marriedid = cache->marriedid;
    arg->childcount = cache->childcount;
    arg->interests1 = cache->interests1;
    arg->ownership1 = cache->ownership1;
    arg->conntypeid = cache->conntypeid;
}
