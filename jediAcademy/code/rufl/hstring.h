////////////////////////////////////////////////////////////////////////////////////////
// RAVEN STANDARD USEFUL FUNCTION LIBRARY
//  (c) 2002 Activision
//
//
// Handle String
// -------------
// Handle strings are allocated once in a static buffer (with a hash index), and are 
// never cleared out.  You should use these for very common string names which are
// redundant or intended to last a long time.
//
// Handle strings are also good for comparison and storage because they compare only
// the handles, which are simple unique integers.
//
////////////////////////////////////////////////////////////////////////////////////////
#if !defined(RUFL_HSTRING_INC)
#define RUFL_HSTRING_INC


#ifdef _XBOX
namespace dllNamespace
{
#endif

////////////////////////////////////////////////////////////////////////////////////////
// The Handle String Class
////////////////////////////////////////////////////////////////////////////////////////
class hstring
{
public:
    ////////////////////////////////////////////////////////////////////////////////////
	// Constructors
    ////////////////////////////////////////////////////////////////////////////////////
	hstring();
	hstring(const char *str);
	hstring(const hstring &str);

	
    ////////////////////////////////////////////////////////////////////////////////////
	// Assignment
    ////////////////////////////////////////////////////////////////////////////////////
	hstring&	operator= (const char *str);
	hstring&	operator= (const hstring &str);



    ////////////////////////////////////////////////////////////////////////////////////
	// Comparison
    ////////////////////////////////////////////////////////////////////////////////////
	bool		operator== (const hstring &str) const	{return (mHandle==str.mHandle);}
	bool		operator<  (const hstring &str) const	{return (mHandle< str.mHandle);}
	bool		operator!  () const						{return (mHandle==0);}


    ////////////////////////////////////////////////////////////////////////////////////
	// Conversion
    ////////////////////////////////////////////////////////////////////////////////////
	const char*	c_str(void) const;
	const char*	operator *(void) const;


    ////////////////////////////////////////////////////////////////////////////////////
	// Access Functions
    ////////////////////////////////////////////////////////////////////////////////////
	int			length(void) const;
	int			handle(void) const;
	bool		empty()	const							{return handle()==0;}



    ////////////////////////////////////////////////////////////////////////////////////
	// Debug Statistics Routines
    ////////////////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
	static	float		ave_collisions();
	static	int			total_strings();
	static	int			total_bytes();
	static	int			total_finds();
	static	int			total_collisions();
#endif



private:
    ////////////////////////////////////////////////////////////////////////////////////
	// Helper Functions
    ////////////////////////////////////////////////////////////////////////////////////
	void		init(const char *str);


    ////////////////////////////////////////////////////////////////////////////////////
	// Data
    ////////////////////////////////////////////////////////////////////////////////////
	int		mHandle;

#ifdef _DEBUG
	char*	mStr;
#endif
};

#ifdef _XBOX
} // dllNamespace
using namespace dllNamespace;
#endif

#endif // HSTRING_H