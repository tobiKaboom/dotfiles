// Appearance
static const unsigned int borderpx  = 3;        // Amount of pixels in the coloured border
static const unsigned int snap      = 16;       // Pixels to snap to the border
static const unsigned int gappx	    = 10;	// Amount of gap pixels between windows and borders
static const int showbar            = 1;        // 1 is bar, 0 is no bar
static const int topbar             = 1;        // 1 is top bar, 0 is bottom bar
static const char *fonts[]          = { "Inconsolata:size=10" };
static const char dmenufont[]       = "Inconsolata:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_blue[]        = "#0496FF";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_gray1,  col_blue },
};

// Tags and stuff
static const char *tags[] = { "#", "#", "#", "#" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

// Layout config
static const float mfact     = 0.45; // Master area size 
static const int nmaster     = 1;    
static const int resizehints = 1;    
static const int lockfullscreen = 1; 
static const int refreshrate = 60;  // Refresh rate

static const Layout layouts[] = {
	{ "><>",      tile },
	{ ">[]",      NULL },
};

// Key definitions
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ ALTKEY,			KEY,	  view,		  {.ui = 1 << TAG} }, \
	{ ALTKEY|ControlMask,		KEY,	  toggleview,	  {.ui = 1 << TAG} }, \
	{ ALTKEY|ShiftMask,		KEY,	  tag,		  {.ui = 1 << TAG} }, \
	{ ALTKEY|ControlMask|ShiftMask,	KEY,	  toggletag,	  {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

// Commands
static char dmenumon[2] = "0";
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_blue, "-sf", col_gray4, NULL };
static const char *termcmd[] = { "kitty", NULL };
static const char *browsercmd[] = { "firefox", NULL };
static const char *filemancmd[] = { "nemo", NULL };
static const char *screenshotcmd[] = { "/bin/sh", "-c", "path=\"/home/tobi/Pictures/Screenshots/maim-temp.png\" && maim -s -B \"$path\" && xclip -selection clipboard -t image/png \"$path\"", NULL }; 

static const Key keys[] = {
	// Modifier                     Key        Function        Argument
	{ MODKEY,                       XK_f,      spawn,          {.v = dmenucmd } },
	{ MODKEY,			XK_z,      spawn,          {.v = termcmd } },
	{ MODKEY,			XK_x,	   spawn,	   {.v = browsercmd} },
	{ MODKEY,			XK_c,	   spawn,	   {.v = screenshotcmd} },
	{ MODKEY,			XK_v,	   spawn,	   {.v = filemancmd} },
	{ MODKEY,                       XK_Left,   focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Right,  focusstack,     {.i = -1 } },
	{ ALTKEY|ShiftMask,             XK_Left,   setmfact,       {.f = -0.02} },
	{ ALTKEY|ShiftMask,             XK_Right,  setmfact,       {.f = +0.02} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ ALTKEY,             	        XK_Escape, killclient,     {0} },
	{ MODKEY,                       XK_e,      togglefloating, {0} },
	{ MODKEY,			XK_r,	   togglefullscr,  {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_m,      quit,           {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
};

// Commands with mouse
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

