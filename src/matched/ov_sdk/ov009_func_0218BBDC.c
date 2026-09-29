/*
 * function: func_0218BBDC
 * address:  0x0218BBDC
 * packet:   pkt_ov009_0218BBDC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiInfoCacheToArg (gpiinfo.o)
 *
 * symbols:
 *   func_0219327C  0x0219327C  arm   ov009
 */

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

extern void func_0219327C(char *dest, char *src, unsigned long len);

void func_0218BBDC(GPIInfoCache *cache, GPGetInfoResponseArg *arg)
{
    if (cache->nick)
        func_0219327C(arg->nick, cache->nick, 31);
    else
        arg->nick[0] = '\0';
    if (cache->uniquenick)
        func_0219327C(arg->uniquenick, cache->uniquenick, 21);
    else
        arg->uniquenick[0] = '\0';
    if (cache->email)
        func_0219327C(arg->email, cache->email, 51);
    else
        arg->email[0] = '\0';
    if (cache->firstname)
        func_0219327C(arg->firstname, cache->firstname, 31);
    else
        arg->firstname[0] = '\0';
    if (cache->lastname)
        func_0219327C(arg->lastname, cache->lastname, 31);
    else
        arg->lastname[0] = '\0';
    if (cache->homepage)
        func_0219327C(arg->homepage, cache->homepage, 76);
    else
        arg->homepage[0] = '\0';
    arg->icquin = cache->icquin;
    func_0219327C(arg->zipcode, cache->zipcode, 11);
    func_0219327C(arg->countrycode, cache->countrycode, 3);
    arg->longitude = cache->longitude;
    arg->latitude = cache->latitude;
    if (cache->place)
        func_0219327C(arg->place, cache->place, 128);
    else
        arg->place[0] = '\0';
    arg->birthday = cache->birthday;
    arg->birthmonth = cache->birthmonth;
    arg->birthyear = cache->birthyear;
    arg->sex = cache->sex;
    arg->publicmask = cache->publicmask;
    if (cache->aimname)
        func_0219327C(arg->aimname, cache->aimname, 51);
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
