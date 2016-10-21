#define	IMAGEMODULE_LIB

#ifdef	IMAGEMODULE_LIB
#define	IMAGEMODULE_EXPORT __declspec( dllexport )
#else
#define		IMAGEMODULE_EXPORT __declspec( dllimport )
#endif