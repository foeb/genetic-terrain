#include "libperlin.h"

/* ---------- Numerical Constant Tables ---------- */

int const perlin_permtable[PERLIN_SIZE] = {
    189,90,95,16,11,8,129,81,184,212,136,127,33,61,132,238,
    28,39,78,188,165,44,248,226,64,5,201,206,31,161,197,199,
    239,56,210,245,60,98,91,215,62,202,103,6,243,17,68,253,
    224,121,193,146,142,187,50,177,83,75,134,87,190,85,233,176,
    106,51,167,12,246,213,94,80,168,147,114,158,65,133,156,22,
    195,104,163,99,219,220,203,241,234,101,84,179,122,36,113,159,
    192,32,209,185,21,229,97,71,139,225,57,2,124,228,73,86,
    247,235,63,217,46,14,205,1,200,70,47,49,204,145,52,154,
    110,237,223,155,216,173,148,45,150,72,171,164,175,116,251,169,
    42,232,250,140,181,35,41,26,34,131,151,240,4,89,162,53,
    112,76,236,191,172,69,183,9,27,18,125,227,182,144,166,77,
    186,88,130,211,170,10,37,7,118,74,160,23,58,221,222,180,
    208,137,231,40,119,242,108,111,59,249,43,30,196,207,252,135,
    20,79,198,105,29,255,3,100,143,24,0,194,82,157,54,48,
    149,13,115,117,96,25,174,178,141,19,126,128,38,230,138,102,
    244,55,120,93,109,152,107,218,67,66,92,153,15,123,254,214
};

double perlin_gradient_grid[PERLIN_SIZE][2] = {
    {-0.94821585776689,-0.31762664730688},
    {0.913766863868,-0.40623899184697},
    {-0.99938256202423,0.03513537707041},
    {-0.94594604006738,-0.32432404980335},
    {0.9277483397531,-0.37320640145283},
    {0.30689903043963,-0.95174207909245},
    {0.39217566423259,-0.91989034584766},
    {-0.82885192053475,-0.55946804540193},
    {-0.55059253502765,-0.83477413734005},
    {0.99956398246986,-0.029527020659103},
    {0.91986686983667,-0.3922307251821},
    {-0.4514213061335,0.89231093480285},
    {0.70403179634905,-0.71016845165744},
    {-0.8471552490446,-0.53134544697041},
    {-0.64815248214089,-0.76151057766429},
    {0.058548344997978,-0.99828457430634},
    {0.15904945199427,-0.98727061731843},
    {0.27844894249999,-0.96045103280731},
    {-0.080241495596651,0.9967754523384},
    {-0.79254134330795,-0.60981818532054},
    {-0.9829453503406,0.18389790168406},
    {0.49843238076087,0.86692857941646},
    {0.28194876354427,-0.95942946313726},
    {0.66171474895621,-0.74975568755017},
    {0.69826140564861,-0.71584286640409},
    {-0.51220495421398,-0.85886325155909},
    {-0.85258302423944,0.52259179746598},
    {-0.76252088225602,-0.64696360339938},
    {-0.82031518551784,-0.57191170333263},
    {-0.60991650897777,-0.79246567880027},
    {-0.97079882992096,-0.23989504335043},
    {0.59618147038989,0.80284970845343},
    {-0.87925195266534,-0.47635701289494},
    {0.97862822406031,0.20563754295498},
    {-0.30357203224781,-0.95280849137533},
    {-0.99350402589928,-0.11379697061842},
    {0.49605395579641,-0.86829169807084},
    {-0.99553289577082,-0.094415324170223},
    {0.75980195120107,0.65015459311693},
    {-0.99795105824905,0.063981914160215},
    {-0.99788662920374,-0.064979037053528},
    {0.95392725008586,0.30003800016603},
    {0.39340460853731,-0.91936544093282},
    {-0.7486899782455,0.66292029420946},
    {-0.64870065181059,-0.76104366782762},
    {-0.95509268151847,0.29630722183212},
    {0.61794854456108,0.78621854231177},
    {-0.85453153492126,0.51939951465621},
    {0.018644027153292,0.99982618501993},
    {-0.83326846018461,0.5528685858878},
    {0.99399083974925,0.10946328377398},
    {-0.2021919972759,-0.97934590224169},
    {-0.89462556019046,-0.44681663694843},
    {0.38527678782615,-0.92280106023041},
    {-0.86806358700303,-0.49645302790842},
    {-0.94453300429886,0.32841650961876},
    {-0.98990059859987,0.14176320006132},
    {0.99953855845127,-0.030375486319696},
    {0.93269966823669,0.36065402932889},
    {0.89310652508545,0.44984523433042},
    {-0.63370659628115,-0.77357349348964},
    {-0.81894463091243,-0.57387253941944},
    {0.17129544610891,0.9852197065337},
    {0.18869060358368,0.98203658593722},
    {-0.683432590778,-0.73001362580603},
    {0.88672519691815,-0.4622969015151},
    {-0.075712085793641,-0.99712972078099},
    {-0.97288421094158,0.23129269789722},
    {-0.92641201486032,0.37651132615427},
    {0.59076227738365,-0.80684566778318},
    {0.95609227917766,-0.29306578390674},
    {0.94891950617605,-0.31551825747268},
    {0.80562859532334,-0.59242093683237},
    {0.10669655517169,-0.99429162981215},
    {-0.50128306836344,0.8652833555386},
    {-0.97346999756828,-0.22881469322229},
    {0.19271068866185,0.98125561933447},
    {-0.99006896139781,0.14058254399694},
    {0.95070705273496,-0.31009047047596},
    {-0.97749215909641,0.21097174906854},
    {0.74726956664043,-0.66452102658458},
    {0.97893762286888,-0.20415957124718},
    {0.40425540990826,0.91464614117149},
    {-0.96544550494902,0.26060502100638},
    {0.188763274018,-0.98202262009691},
    {0.10315944796921,-0.99466483213929},
    {0.82630815188829,-0.563218286389},
    {-0.047642208786547,0.99886446525139},
    {0.072898417912448,-0.99733937085922},
    {0.97382428417044,-0.22730214156478},
    {-0.49188398697209,0.8706607510164},
    {-0.8177115095999,0.57562825422998},
    {-0.92795062616877,-0.37270314647583},
    {-0.94204961560746,-0.33547357829468},
    {-0.71958248385673,-0.69440697643858},
    {0.36211332524846,0.93213407816553},
    {-0.99042752669201,0.13803374359463},
    {-0.63793274377121,0.77009208178278},
    {-0.56789014244663,-0.82310435918658},
    {0.86557269272101,-0.50078330005672},
    {0.24447885945268,0.96965462267795},
    {-0.78417910487639,-0.62053455300674},
    {0.66335253793099,-0.7483070295143},
    {0.77140286009783,0.63634709666415},
    {-0.70066152327932,0.71349381903132},
    {0.31497022185054,0.94910155375883},
    {-0.60533197230861,-0.79597311719742},
    {-0.83514478395492,-0.55003017174778},
    {-0.44526935135767,-0.89539667452003},
    {-0.82231705371772,-0.5690295802197},
    {0.9323883054003,0.36145822435347},
    {-0.92774615257978,-0.37321183846902},
    {-0.92116993693558,-0.3891605674861},
    {0.046316646493664,0.99892680825853},
    {0.99294923139911,0.11854038916724},
    {-0.55604753334401,0.83115049218661},
    {0.99837536573999,0.056979198691724},
    {0.88724615917095,-0.46129627468298},
    {-0.80371535924258,-0.59501396732981},
    {0.12960758572163,-0.9915653653307},
    {0.75916822470633,-0.65089446655832},
    {0.91339002414664,-0.40708557305486},
    {0.46479142562419,0.88542020005545},
    {-0.94706104519366,0.32105354176007},
    {-0.99702517501188,0.077076587836537},
    {0.28038619828066,-0.95988727453473},
    {-0.64220837147866,-0.76653010873855},
    {0.97684200817411,-0.21396189162178},
    {0.56033405273849,0.82826671389212},
    {-0.26623047321128,0.96390940193241},
    {0.73837922520553,-0.67438573515821},
    {-0.66614281999193,0.74582420406769},
    {0.80691146404076,-0.59067240429836},
    {-0.014841853227461,-0.99988985363028},
    {-0.98846754345573,0.15143287468247},
    {-0.14393070600709,0.98958776865334},
    {0.94432227186446,-0.32902195498287},
    {0.71888750495027,0.69512643110903},
    {0.66450610872467,-0.74728283231157},
    {-0.71508292775615,-0.69903963151719},
    {-0.19560595373159,-0.98068257395793},
    {0.88968925029911,-0.45656657554206},
    {0.40252556896002,0.91540874276654},
    {-0.20145666294204,0.9794974287645},
    {0.49728401202065,0.86758781191799},
    {0.2911745457027,0.95666994514034},
    {-0.70209028950849,-0.71208793373985},
    {0.44704164905997,0.89451314356232},
    {0.69965177702701,0.71448400325196},
    {0.14057847981403,0.99006953847352},
    {0.94490824084116,-0.32733532713481},
    {0.99620708163936,0.087014082145276},
    {0.53144600650549,0.84709216863891},
    {0.7290145571788,0.68449819241646},
    {-0.97140509991712,0.23742816146153},
    {-0.59515602158724,-0.8036101728876},
    {0.8614467245212,-0.50784795048487},
    {0.80584032168654,0.59213290395327},
    {-0.75331535602174,-0.65765946688377},
    {0.90333148747422,0.42894314744218},
    {-0.78530172348943,0.61911323930645},
    {-0.99974857197293,0.022423042569971},
    {-0.92166396598494,0.38798908980139},
    {-0.26797586063933,0.96342562666488},
    {0.03725869432282,0.99930565379035},
    {0.8522806146652,-0.52308484385032},
    {-0.91482426134007,-0.40385216461423},
    {0.36397771470517,0.9314076568281},
    {0.97630398526704,0.21640362370278},
    {-0.9096981006931,0.41527023201207},
    {0.39081661535204,-0.9204685617471},
    {0.021252393461724,-0.99977414238024},
    {-0.61975011344987,0.78479920800092},
    {0.99991864935596,-0.012755182089783},
    {0.97499476554035,0.22222782717051},
    {-0.9890740505311,-0.14741954607856},
    {0.30335335781597,0.95287813507383},
    {-0.52628860045028,-0.85030600905561},
    {-0.31028857022516,-0.95064241604697},
    {-0.46857446869575,0.88342400198687},
    {0.7678772265522,-0.64059703788146},
    {-0.60437307328954,-0.79670144237509},
    {-0.54366753512376,0.83930066796855},
    {0.95073001958034,0.31002004752719},
    {0.10474392880637,-0.99449922542866},
    {0.32884780176938,-0.94438293253926},
    {-0.31669743206505,-0.94852661350296},
    {-0.41482307900902,-0.90990208985444},
    {0.82419902665213,-0.56630024233236},
    {-0.38523446817417,0.92281872788244},
    {0.015573520212017,-0.99987872538034},
    {-0.29664094147196,0.95498908467198},
    {0.36444520581221,-0.93122483426963},
    {0.37358848416914,0.92759454747007},
    {-0.84056834576641,-0.54170550679822},
    {0.9441569943564,0.32949593321905},
    {0.8036128719393,0.59515237717199},
    {0.55020337451769,0.8350306860645},
    {0.036757070034794,0.99932423056907},
    {0.65577731620202,0.75495437713472},
    {-0.84728235153288,-0.53114274614355},
    {0.93421180988849,0.35671878877467},
    {0.76872070248327,-0.63958461642978},
    {0.94194374097787,-0.33577073849966},
    {0.93868582426176,0.34477372772591},
    {0.89163216068456,-0.45276052172531},
    {-0.98115128111748,0.19324120565117},
    {-0.04377384997386,0.99904146563517},
    {-0.85424083424933,-0.51987748277937},
    {0.48814331481259,0.87276348697902},
    {-0.86206589974518,-0.50679619621357},
    {-0.98898405814075,0.14802206843394},
    {0.40031125623064,-0.91637923270611},
    {0.89403162883467,-0.44800384668351},
    {-0.98614664165176,-0.1658758606879},
    {-0.86940826340213,-0.49409439536195},
    {-0.12908685066525,-0.99163329158784},
    {0.1549724406505,0.98791879354471},
    {-0.088926913099098,0.99603815395128},
    {-0.66795543000291,-0.74420127890889},
    {-0.97137069006573,-0.23756890049254},
    {0.99453245472444,0.10442794884403},
    {0.90884702577429,-0.41712957667999},
    {-0.57524145104973,0.81798366303625},
    {0.27467907626631,0.96153596139795},
    {-0.98990942974578,-0.14170152045897},
    {-0.81264052986239,0.58276527798503},
    {-0.35152477456144,0.93617857958272},
    {-0.42632638822115,-0.90456940624051},
    {-0.61224174558065,-0.79067062988855},
    {-0.93729408967617,0.34853950917812},
    {-0.11923665377548,0.9928658622374},
    {-0.28991639981464,-0.95705197409468},
    {-0.49759686276097,0.86740841716601},
    {0.22106108407559,0.97525996385955},
    {0.057825962009055,-0.99832667905738},
    {-0.050945078388415,0.99870145638624},
    {-0.40535477441084,-0.91415945374006},
    {0.99483848364259,0.10147113611125},
    {0.56272176787622,-0.8266463645104},
    {0.59997376924499,-0.80001967239435},
    {-0.80619114669583,-0.59165516560685},
    {-0.43416095286013,0.90083531625463},
    {-0.49294516026663,-0.87006038236993},
    {-0.9858241741346,-0.16778169653402},
    {0.57757320140962,-0.81633889838317},
    {-0.0013213657413978,0.99999912699591},
    {-0.039120978053518,0.9992344815288},
    {0.89598446829108,0.44408538883997},
    {-0.99591977942943,-0.090242966159295},
    {0.76976265066912,-0.63833021363152},
    {-0.76483217181566,-0.64422957783366},
    {-0.98105065509096,-0.19375141843504},
    {0.43333008381859,-0.90123528473855},
    {0.96693243823743,-0.25503266434756},
    {-0.82885192053475,-0.55946804540193}
};

/* ---------- Algorithms ---------- */

/* lerp: linear interpolation between a1 and a2 with a weight w 
 * between 0 and 1 */
double perlin_lerp(double a1, double a2, double w) 
{
    MAKE_KOSHER(a1);
    MAKE_KOSHER(a2);
    assert(KOSHER(a1));
    assert(KOSHER(a2));
    return (1.0 - w) * a1 + w * a2;
}

/* perlin_get: returns the gradient at x, y as a pointer to two values */
double *perlin_get(int x, int y)
{
    x = abs(x);
    y = abs(y);
    return perlin_gradient_grid[(x + perlin_permtable[y & (PERLIN_SIZE-1)]) 
                                                            & (PERLIN_SIZE-1)];
}

/* perlin_dot_grid: perform the dot product of x, y and the gradient at
 * gx, gy.  */
double perlin_dot_grid(int gx, int gy, double x, double y)
{
    MAKE_KOSHER(x);
    MAKE_KOSHER(y);
    assert(KOSHER(x));
    assert(KOSHER(y));
    double *p = perlin_get(gx, gy);
    /* assert(p[0]);
    assert(p[1]); */
    return (x - gx) * p[0] + (y - gy) * p[1];
}

/* perlin_generate: return the value of this perlin noise at x, y */
double perlin_generate(double x, double y)
{
    MAKE_KOSHER(x);
    MAKE_KOSHER(y);
    assert(KOSHER(x));
    assert(KOSHER(y));
    int x0 = floor(x);
    int x1 = x0 + 1;
    int y0 = floor(y);
    int y1 = y0 + 1;
    double psx = fabs(fmod(x - x0, 1.0));
    double sx = PERLIN_WEIGHT(psx);
    double psy = fabs(fmod(y - y0, 1.0));
    double sy = PERLIN_WEIGHT(psy);
    double n0 = perlin_dot_grid(x0, y0, x, y);
    double n1 = perlin_dot_grid(x1, y0, x, y);
    double ix0 = perlin_lerp(n0, n1, sx);
    n0 = perlin_dot_grid(x0, y1, x, y);
    n1 = perlin_dot_grid(x1, y1, x, y);
    double ix1 = perlin_lerp(n0, n1, sx);
    return perlin_lerp(ix0, ix1, sy);
}

/* l_perlin_generate: Lua interface to perlin_generate */
int l_perlin_generate(lua_State *L)
{
    double x = luaL_checknumber(L, 1);
    double y = luaL_checknumber(L, 2);
    lua_pushnumber(L, perlin_generate(x, y));
    return 1;
}

