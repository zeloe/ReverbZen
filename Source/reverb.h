/* ------------------------------------------------------------
name: "reverb"
Code generated with Faust 2.50.6 (https://faust.grame.fr)
Compilation options: -a faustMinimal.h -lang cpp -i -es 1 -mcd 16 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#include <cmath>
#include <cstring>

/************************** BEGIN MapUI.h ******************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ***********************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#include <vector>
#include <map>
#include <string>
#include <stdio.h>

/************************** BEGIN UI.h *****************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef __UI_H__
#define __UI_H__

/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2003-2018 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 ************************************************************************
 ************************************************************************/

#ifndef __export__
#define __export__

#define FAUSTVERSION "2.50.6"

// Use FAUST_API for code that is part of the external API but is also compiled in faust and libfaust
// Use LIBFAUST_API for code that is compiled in faust and libfaust

#ifdef _WIN32
    #pragma warning (disable: 4251)
    #ifdef FAUST_EXE
        #define FAUST_API
        #define LIBFAUST_API
    #elif FAUST_LIB
        #define FAUST_API __declspec(dllexport)
        #define LIBFAUST_API __declspec(dllexport)
    #else
        #define FAUST_API
        #define LIBFAUST_API 
    #endif
#else
    #ifdef FAUST_EXE
        #define FAUST_API
        #define LIBFAUST_API
    #else
        #define FAUST_API __attribute__((visibility("default")))
        #define LIBFAUST_API __attribute__((visibility("default")))
    #endif
#endif

#endif

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

struct Soundfile;

template <typename REAL>
struct FAUST_API UIReal {
    
    UIReal() {}
    virtual ~UIReal() {}
    
    // -- widget's layouts
    
    virtual void openTabBox(const char* label) = 0;
    virtual void openHorizontalBox(const char* label) = 0;
    virtual void openVerticalBox(const char* label) = 0;
    virtual void closeBox() = 0;
    
    // -- active widgets
    
    virtual void addButton(const char* label, REAL* zone) = 0;
    virtual void addCheckButton(const char* label, REAL* zone) = 0;
    virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
    virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
    
    // -- soundfiles
    
    virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;
    
    // -- metadata declarations
    
    virtual void declare(REAL* zone, const char* key, const char* val) {}
    
    // To be used by LLVM client
    virtual int sizeOfFAUSTFLOAT() { return sizeof(FAUSTFLOAT); }
};

struct FAUST_API UI : public UIReal<FAUSTFLOAT> {
    UI() {}
    virtual ~UI() {}
};

#endif
/**************************  END  UI.h **************************/
/************************** BEGIN PathBuilder.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __PathBuilder__
#define __PathBuilder__

#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <regex>


/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class FAUST_API PathBuilder {

    protected:
    
        std::vector<std::string> fControlsLevel;
        std::vector<std::string> fFullPaths;
        std::map<std::string, std::string> fFull2Short;  // filled by computeShortNames()
    
        /**
         * @brief check if a character is acceptable for an ID
         *
         * @param c
         * @return true is the character is acceptable for an ID
         */
        bool isIDChar(char c) const
        {
            return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9'));
        }
    
        /**
         * @brief remove all "/0x00" parts
         *
         * @param src
         * @return modified string
         */
        std::string remove0x00(const std::string& src) const
        {
            return std::regex_replace(src, std::regex("/0x00"), "");
        }
    
        /**
         * @brief replace all non ID char with '_' (one '_' may replace several non ID char)
         *
         * @param src
         * @return modified string
         */
        std::string str2ID(const std::string& src) const
        {
            std::string dst;
            bool need_underscore = false;
            for (char c : src) {
                if (isIDChar(c) || (c == '/')) {
                    if (need_underscore) {
                        dst.push_back('_');
                        need_underscore = false;
                    }
                    dst.push_back(c);
                } else {
                    need_underscore = true;
                }
            }
            return dst;
        }
    
        /**
         * @brief Keep only the last n slash-parts
         *
         * @param src
         * @param n : 1 indicates the last slash-part
         * @return modified string
         */
        std::string cut(const std::string& src, int n) const
        {
            std::string rdst;
            for (int i = int(src.length())-1; i >= 0; i--) {
                char c = src[i];
                if (c != '/') {
                    rdst.push_back(c);
                } else if (n == 1) {
                    std::string dst;
                    for (int j = int(rdst.length())-1; j >= 0; j--) {
                        dst.push_back(rdst[j]);
                    }
                    return dst;
                } else {
                    n--;
                    rdst.push_back(c);
                }
            }
            return src;
        }
    
        void addFullPath(const std::string& label) { fFullPaths.push_back(buildPath(label)); }
    
        /**
         * @brief Compute the mapping between full path and short names
         */
        void computeShortNames()
        {
            std::vector<std::string>           uniquePaths;  // all full paths transformed but made unique with a prefix
            std::map<std::string, std::string> unique2full;  // all full paths transformed but made unique with a prefix
            char num_buffer[16];
            int pnum = 0;
        
            for (const auto& s : fFullPaths) {
                sprintf(num_buffer, "%d", pnum++);
                std::string u = "/P" + std::string(num_buffer) + str2ID(remove0x00(s));
                uniquePaths.push_back(u);
                unique2full[u] = s;  // remember the full path associated to a unique path
            }
        
            std::map<std::string, int> uniquePath2level;                // map path to level
            for (const auto& s : uniquePaths) uniquePath2level[s] = 1;   // we init all levels to 1
            bool have_collisions = true;
        
            while (have_collisions) {
                // compute collision list
                std::set<std::string>              collisionSet;
                std::map<std::string, std::string> short2full;
                have_collisions = false;
                for (const auto& it : uniquePath2level) {
                    std::string u = it.first;
                    int n = it.second;
                    std::string shortName = cut(u, n);
                    auto p = short2full.find(shortName);
                    if (p == short2full.end()) {
                        // no collision
                        short2full[shortName] = u;
                    } else {
                        // we have a collision, add the two paths to the collision set
                        have_collisions = true;
                        collisionSet.insert(u);
                        collisionSet.insert(p->second);
                    }
                }
                for (const auto& s : collisionSet) uniquePath2level[s]++;  // increase level of colliding path
            }
        
            for (const auto& it : uniquePath2level) {
                std::string u = it.first;
                int n = it.second;
                std::string shortName = replaceCharList(cut(u, n), {'/'}, '_');
                fFull2Short[unique2full[u]] = shortName;
            }
        }
    
        std::string replaceCharList(const std::string& str, const std::vector<char>& ch1, char ch2)
        {
            auto beg = ch1.begin();
            auto end = ch1.end();
            std::string res = str;
            for (size_t i = 0; i < str.length(); ++i) {
                if (std::find(beg, end, str[i]) != end) res[i] = ch2;
            }
            return res;
        }
     
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        // Return true for the first level of groups
        bool pushLabel(const std::string& label) { fControlsLevel.push_back(label); return fControlsLevel.size() == 1;}
    
        // Return true for the last level of groups
        bool popLabel() { fControlsLevel.pop_back(); return fControlsLevel.size() == 0; }
    
        std::string buildPath(const std::string& label)
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res = res + fControlsLevel[i] + "/";
            }
            res += label;
            return replaceCharList(res, {' ', '#', '*', ',', '?', '[', ']', '{', '}', '(', ')'}, '_');
        }
    
};

#endif  // __PathBuilder__
/**************************  END  PathBuilder.h **************************/

/*******************************************************************************
 * MapUI : Faust User Interface.
 *
 * This class creates:
 * - a map of 'labels' and zones for each UI item.
 * - a map of unique 'shortname' (built so that they never collide) and zones for each UI item
 * - a map of complete hierarchical 'paths' and zones for each UI item
 *
 * Simple 'labels', 'shortname' and complete 'paths' (to fully discriminate between possible same
 * 'labels' at different location in the UI hierachy) can be used to access a given parameter.
 ******************************************************************************/

class FAUST_API MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
        // Shortname zone map
        std::map<std::string, FAUSTFLOAT*> fShortnameZoneMap;
    
        // Full path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        void addZoneLabel(const std::string& label, FAUSTFLOAT* zone)
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);
            fPathZoneMap[path] = zone;
            fLabelZoneMap[label] = zone;
        }
    
    public:
        
        MapUI() {}
        virtual ~MapUI() {}
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            pushLabel(label);
        }
        void openHorizontalBox(const char* label)
        {
            pushLabel(label);
        }
        void openVerticalBox(const char* label)
        {
            pushLabel(label);
        }
        void closeBox()
        {
            if (popLabel()) {
                // Shortnames can be computed when all fullnames are known
                computeShortNames();
                // Fill 'shortname' map
                for (const auto& it : fFullPaths) {
                    fShortnameZoneMap[fFull2Short[it]] = fPathZoneMap[it];
                }
            }
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addZoneLabel(label, zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addZoneLabel(label, zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            addZoneLabel(label, zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            addZoneLabel(label, zone);
        }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
        
        // -- metadata declarations
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
    
        //-------------------------------------------------------------------------------
        // Public API
        //-------------------------------------------------------------------------------
    
        /**
         * Set the param value.
         *
         * @param str - the UI parameter label/shortname/path
         * @param value - the UI parameter value
         *
         */
        void setParamValue(const std::string& str, FAUSTFLOAT value)
        {
            if (fPathZoneMap.find(str) != fPathZoneMap.end()) {
                *fPathZoneMap[str] = value;
            } else if (fShortnameZoneMap.find(str) != fShortnameZoneMap.end()) {
                *fShortnameZoneMap[str] = value;
            } else if (fLabelZoneMap.find(str) != fLabelZoneMap.end()) {
                *fLabelZoneMap[str] = value;
            } else {
                fprintf(stderr, "ERROR : setParamValue '%s' not found\n", str.c_str());
            }
        }
        
        /**
         * Return the param value.
         *
         * @param str - the UI parameter label/shortname/path
         *
         * @return the param value.
         */
        FAUSTFLOAT getParamValue(const std::string& str)
        {
            if (fPathZoneMap.find(str) != fPathZoneMap.end()) {
                return *fPathZoneMap[str];
            } else if (fShortnameZoneMap.find(str) != fShortnameZoneMap.end()) {
                return *fShortnameZoneMap[str];
            } else if (fLabelZoneMap.find(str) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[str];
            } else {
                fprintf(stderr, "ERROR : getParamValue '%s' not found\n", str.c_str());
                return 0;
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getFullpathMap() { return fPathZoneMap; }
        std::map<std::string, FAUSTFLOAT*>& getShortnameMap() { return fShortnameZoneMap; }
        std::map<std::string, FAUSTFLOAT*>& getLabelMap() { return fLabelZoneMap; }
            
        /**
         * Return the number of parameters in the UI.
         *
         * @return the number of parameters
         */
        int getParamsCount() { return int(fPathZoneMap.size()); }
        
        /**
         * Return the param path.
         *
         * @param index - the UI parameter index
         *
         * @return the param path
         */
        std::string getParamAddress(int index)
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return "";
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamAddress1(int index)
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param shortname.
         *
         * @param index - the UI parameter index
         *
         * @return the param shortname
         */
        std::string getParamShortname(int index)
        {
            if (index < 0 || index > int(fShortnameZoneMap.size())) {
                return "";
            } else {
                auto it = fShortnameZoneMap.begin();
                while (index-- > 0 && it++ != fShortnameZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamShortname1(int index)
        {
            if (index < 0 || index > int(fShortnameZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fShortnameZoneMap.begin();
                while (index-- > 0 && it++ != fShortnameZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param label.
         *
         * @param index - the UI parameter index
         *
         * @return the param label
         */
        std::string getParamLabel(int index)
        {
            if (index < 0 || index > int(fLabelZoneMap.size())) {
                return "";
            } else {
                auto it = fLabelZoneMap.begin();
                while (index-- > 0 && it++ != fLabelZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamLabel1(int index)
        {
            if (index < 0 || index > int(fLabelZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fLabelZoneMap.begin();
                while (index-- > 0 && it++ != fLabelZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param path.
         *
         * @param zone - the UI parameter memory zone
         *
         * @return the param path
         */
        std::string getParamAddress(FAUSTFLOAT* zone)
        {
            for (const auto& it : fPathZoneMap) {
                if (it.second == zone) return it.first;
            }
            return "";
        }
    
        /**
         * Return the param memory zone.
         *
         * @param zone - the UI parameter label/shortname/path
         *
         * @return the param path
         */
        FAUSTFLOAT* getParamZone(const std::string& str)
        {
            if (fPathZoneMap.find(str) != fPathZoneMap.end()) {
                return fPathZoneMap[str];
            } else if (fShortnameZoneMap.find(str) != fShortnameZoneMap.end()) {
                return fShortnameZoneMap[str];
            } else if (fLabelZoneMap.find(str) != fLabelZoneMap.end()) {
                return fLabelZoneMap[str];
            }
            return nullptr;
        }
    
        /**
         * Return the param memory zone.
         *
         * @param zone - the UI parameter index
         *
         * @return the param path
         */
        FAUSTFLOAT* getParamZone(int index)
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->second;
            }
        }
    
        static bool endsWith(const std::string& str, const std::string& end)
        {
            size_t l1 = str.length();
            size_t l2 = end.length();
            return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
        }
    
};

#endif // FAUST_MAPUI_H
/**************************  END  MapUI.h **************************/
/************************** BEGIN meta.h *******************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __meta__
#define __meta__


/**
 The base class of Meta handler to be used in dsp::metadata(Meta* m) method to retrieve (key, value) metadata.
 */
struct FAUST_API Meta {
    virtual ~Meta() {}
    virtual void declare(const char* key, const char* value) = 0;
};

#endif
/**************************  END  meta.h **************************/
/************************** BEGIN dsp.h ********************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp__
#define __dsp__

#include <string>
#include <vector>


#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

struct FAUST_API UI;
struct FAUST_API Meta;

/**
 * DSP memory manager.
 */

struct FAUST_API dsp_memory_manager {
    
    virtual ~dsp_memory_manager() {}
    
    /**
     * Inform the Memory Manager with the number of expected memory zones.
     * @param count - the number of expected memory zones
     */
    virtual void begin(size_t count) {}
    
    /**
     * Give the Memory Manager information on a given memory zone.
     * @param size - the size in bytes of the memory zone
     * @param reads - the number of Read access to the zone used to compute one frame
     * @param writes - the number of Write access to the zone used to compute one frame
     */
    virtual void info(size_t size, size_t reads, size_t writes) {}
    
    /**
     * Inform the Memory Manager that all memory zones have been described,
     * to possibly start a 'compute the best allocation strategy' step.
     */
    virtual void end() {}
    
    /**
     * Allocate a memory zone.
     * @param size - the memory zone size in bytes
     */
    virtual void* allocate(size_t size) = 0;
    
    /**
     * Destroy a memory zone.
     * @param ptr - the memory zone pointer to be deallocated
     */
    virtual void destroy(void* ptr) = 0;
    
};

/**
* Signal processor definition.
*/

class FAUST_API dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the ui_interface parameter with instance specific calls
         * to 'openTabBox', 'addButton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Return the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /**
         * Global init, calls the following methods:
         * - static class 'classInit': static tables initialization
         * - 'instanceInit': constants and instance state initialization
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void init(int sample_rate) = 0;

        /**
         * Init instance state
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void instanceInit(int sample_rate) = 0;
    
        /**
         * Init instance constant state
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void instanceConstants(int sample_rate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (like delay lines...) but keep the control parameter values */
        virtual void instanceClear() = 0;
 
        /**
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value) metadata.
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with successive in/out audio buffers.
         *
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         *
         */
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class FAUST_API decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = nullptr):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int sample_rate) { fDSP->init(sample_rate); }
        virtual void instanceInit(int sample_rate) { fDSP->instanceInit(sample_rate); }
        virtual void instanceConstants(int sample_rate) { fDSP->instanceConstants(sample_rate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
    
};

/**
 * DSP factory class, used with LLVM and Interpreter backends
 * to create DSP instances from a compiled DSP program.
 */

class FAUST_API dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        virtual ~dsp_factory() {}
    
    public:
    
        virtual std::string getName() = 0;
        virtual std::string getSHAKey() = 0;
        virtual std::string getDSPCode() = 0;
        virtual std::string getCompileOptions() = 0;
        virtual std::vector<std::string> getLibraryList() = 0;
        virtual std::vector<std::string> getIncludePathnames() = 0;
    
        virtual dsp* createDSPInstance() = 0;
    
        virtual void setMemoryManager(dsp_memory_manager* manager) = 0;
        virtual dsp_memory_manager* getMemoryManager() = 0;
    
};

// Denormal handling

#if defined (__SSE__)
#include <xmmintrin.h>
#endif

class FAUST_API ScopedNoDenormals {
    
    private:
    
        intptr_t fpsr = 0;
        
        void setFpStatusRegister(intptr_t fpsr_aux) noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            asm volatile("msr fpcr, %0" : : "ri" (fpsr_aux));
        #elif defined (__SSE__)
            // The volatile keyword here is needed to workaround a bug in AppleClang 13.0
            // which aggressively optimises away the variable otherwise
            volatile uint32_t fpsr_w = static_cast<uint32_t>(fpsr_aux);
            _mm_setcsr(fpsr_w);
        #endif
        }
        
        void getFpStatusRegister() noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            asm volatile("mrs %0, fpcr" : "=r" (fpsr));
        #elif defined (__SSE__)
            fpsr = static_cast<intptr_t>(_mm_getcsr());
        #endif
        }
    
    public:
    
        ScopedNoDenormals() noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            intptr_t mask = (1 << 24 /* FZ */);
        #elif defined (__SSE__)
        #if defined (__SSE2__)
            intptr_t mask = 0x8040;
        #else
            intptr_t mask = 0x8000;
        #endif
        #else
            intptr_t mask = 0x0000;
        #endif
            getFpStatusRegister();
            setFpStatusRegister(fpsr | mask);
        }
        
        ~ScopedNoDenormals() noexcept
        {
            setFpStatusRegister(fpsr);
        }

};

#define AVOIDDENORMALS ScopedNoDenormals ftz_scope;

#endif

/************************** END dsp.h **************************/

// BEGIN-FAUSTDSP


#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif


class mydsp : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fEntry0;
	float fConst2;
	float fRec0[2];
	float fConst3;
	FAUSTFLOAT fEntry1;
	float fRec2[2];
	int IOTA0;
	FAUSTFLOAT fEntry2;
	float fRec8[2];
	FAUSTFLOAT fEntry3;
	float fRec10[2];
	float fVec0[2];
	float fRec9[2];
	FAUSTFLOAT fEntry4;
	float fRec11[2];
	float fVec1[2];
	float fRec7[32768];
	float fConst4;
	FAUSTFLOAT fEntry5;
	float fRec12[2];
	float fVec2[32768];
	float fConst5;
	FAUSTFLOAT fEntry6;
	float fRec13[2];
	float fRec5[2];
	float fRec6[3];
	FAUSTFLOAT fEntry7;
	float fRec14[2];
	float fRec4[2];
	float fVec3[16384];
	float fConst6;
	FAUSTFLOAT fEntry8;
	float fRec15[2];
	float fRec3[2];
	float fVec4[2];
	float fRec20[32768];
	float fConst7;
	float fVec5[32768];
	float fConst8;
	float fRec18[2];
	float fRec19[3];
	float fRec17[2];
	float fVec6[16384];
	float fConst9;
	float fRec16[2];
	float fConst10;
	float fVec7[32768];
	float fConst11;
	float fRec23[2];
	float fRec24[3];
	float fRec22[2];
	float fVec8[16384];
	float fRec21[2];
	float fRec29[32768];
	float fVec9[32768];
	float fRec27[2];
	float fRec28[3];
	float fRec26[2];
	float fVec10[16384];
	float fRec25[2];
	FAUSTFLOAT fEntry9;
	float fRec30[2];
	float fVec11[2];
	float fRec1[2];
	float fRec36[32768];
	float fVec12[32768];
	float fRec34[2];
	float fRec35[3];
	float fRec33[2];
	float fVec13[16384];
	float fConst12;
	float fRec32[2];
	float fRec41[32768];
	float fVec14[32768];
	float fRec39[2];
	float fRec40[3];
	float fRec38[2];
	float fVec15[16384];
	float fConst13;
	float fRec37[2];
	float fRec46[32768];
	float fConst14;
	float fVec16[32768];
	float fConst15;
	float fRec44[2];
	float fRec45[3];
	float fRec43[2];
	float fVec17[16384];
	float fRec42[2];
	float fRec51[32768];
	float fVec18[32768];
	float fRec49[2];
	float fRec50[3];
	float fRec48[2];
	float fVec19[16384];
	float fConst16;
	float fRec47[2];
	float fVec20[2];
	float fRec31[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-a faustMinimal.h -lang cpp -i -es 1 -mcd 16 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "reverb.dsp");
		m->declare("filters.lib/fb_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/fb_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fb_comb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fbcombfilter:author", "Julius O. Smith III");
		m->declare("filters.lib/fbcombfilter:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fbcombfilter:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "reverb");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.3");
	}

	virtual int getNumInputs() {
		return 2;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 3.1415927f / fConst0;
		fConst4 = 0.5f * fConst0;
		fConst5 = 0.55f * fConst0;
		fConst6 = 0.122f * fConst0;
		fConst7 = 0.51f * fConst0;
		fConst8 = 0.54f * fConst0;
		fConst9 = 0.13f * fConst0;
		fConst10 = 0.52f * fConst0;
		fConst11 = 0.53f * fConst0;
		fConst12 = 0.12f * fConst0;
		fConst13 = 0.14f * fConst0;
		fConst14 = 0.59f * fConst0;
		fConst15 = 0.56f * fConst0;
		fConst16 = 0.11f * fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fEntry0 = FAUSTFLOAT(1.0f);
		fEntry1 = FAUSTFLOAT(5e+03f);
		fEntry2 = FAUSTFLOAT(1.0f);
		fEntry3 = FAUSTFLOAT(1.0f);
		fEntry4 = FAUSTFLOAT(1.0f);
		fEntry5 = FAUSTFLOAT(1.0f);
		fEntry6 = FAUSTFLOAT(1.0f);
		fEntry7 = FAUSTFLOAT(1.0f);
		fEntry8 = FAUSTFLOAT(1.0f);
		fEntry9 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec2[l1] = 0.0f;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec8[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec10[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fVec0[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec9[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec11[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fVec1[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 32768; l8 = l8 + 1) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec12[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 32768; l10 = l10 + 1) {
			fVec2[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec13[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec5[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 3; l13 = l13 + 1) {
			fRec6[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec14[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec4[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 16384; l16 = l16 + 1) {
			fVec3[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec15[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec3[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fVec4[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 32768; l20 = l20 + 1) {
			fRec20[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 32768; l21 = l21 + 1) {
			fVec5[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec18[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 3; l23 = l23 + 1) {
			fRec19[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			fRec17[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 16384; l25 = l25 + 1) {
			fVec6[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fRec16[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 32768; l27 = l27 + 1) {
			fVec7[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fRec23[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 3; l29 = l29 + 1) {
			fRec24[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fRec22[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 16384; l31 = l31 + 1) {
			fVec8[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fRec21[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 32768; l33 = l33 + 1) {
			fRec29[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 32768; l34 = l34 + 1) {
			fVec9[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fRec27[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 3; l36 = l36 + 1) {
			fRec28[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			fRec26[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 16384; l38 = l38 + 1) {
			fVec10[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = l39 + 1) {
			fRec25[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fRec30[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			fVec11[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fRec1[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 32768; l43 = l43 + 1) {
			fRec36[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 32768; l44 = l44 + 1) {
			fVec12[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			fRec34[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 3; l46 = l46 + 1) {
			fRec35[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = l47 + 1) {
			fRec33[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 16384; l48 = l48 + 1) {
			fVec13[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = l49 + 1) {
			fRec32[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 32768; l50 = l50 + 1) {
			fRec41[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 32768; l51 = l51 + 1) {
			fVec14[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			fRec39[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 3; l53 = l53 + 1) {
			fRec40[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 2; l54 = l54 + 1) {
			fRec38[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 16384; l55 = l55 + 1) {
			fVec15[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2; l56 = l56 + 1) {
			fRec37[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 32768; l57 = l57 + 1) {
			fRec46[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 32768; l58 = l58 + 1) {
			fVec16[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 2; l59 = l59 + 1) {
			fRec44[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 3; l60 = l60 + 1) {
			fRec45[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = l61 + 1) {
			fRec43[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 16384; l62 = l62 + 1) {
			fVec17[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 2; l63 = l63 + 1) {
			fRec42[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 32768; l64 = l64 + 1) {
			fRec51[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 32768; l65 = l65 + 1) {
			fVec18[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 2; l66 = l66 + 1) {
			fRec49[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 3; l67 = l67 + 1) {
			fRec50[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 2; l68 = l68 + 1) {
			fRec48[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 16384; l69 = l69 + 1) {
			fVec19[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 2; l70 = l70 + 1) {
			fRec47[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 2; l71 = l71 + 1) {
			fVec20[l71] = 0.0f;
		}
		for (int l72 = 0; l72 < 2; l72 = l72 + 1) {
			fRec31[l72] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("reverb");
		ui_interface->addNumEntry("damp", &fEntry2, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addNumEntry("decaydelay", &fEntry8, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addNumEntry("delaywet", &fEntry0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addNumEntry("erdelay", &fEntry6, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addNumEntry("highpasscutoff", &fEntry1, FAUSTFLOAT(5e+03f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->addNumEntry("lowpassfc", &fEntry7, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addNumEntry("mixhighpassin", &fEntry4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addNumEntry("mixhighpassout", &fEntry9, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addNumEntry("predelay", &fEntry5, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addNumEntry("width", &fEntry3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = fConst1 * float(fEntry0);
		float fSlow1 = fConst1 * float(fEntry1);
		float fSlow2 = fConst1 * float(fEntry2);
		float fSlow3 = fConst1 * float(fEntry3);
		float fSlow4 = fConst1 * float(fEntry4);
		float fSlow5 = fConst1 * float(fEntry5);
		float fSlow6 = fConst1 * float(fEntry6);
		float fSlow7 = fConst1 * float(fEntry7);
		float fSlow8 = fConst1 * float(fEntry8);
		float fSlow9 = fConst1 * float(fEntry9);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = float(input0[i0]);
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			float fTemp1 = 1.0f - fRec0[0];
			fRec2[0] = fSlow1 + fConst2 * fRec2[1];
			float fTemp2 = std::tan(fConst3 * fRec2[0]);
			float fTemp3 = 1.0f / fTemp2;
			float fTemp4 = fTemp3 + 1.0f;
			float fTemp5 = fTemp2 * fTemp4;
			float fTemp6 = 0.0f - 1.0f / fTemp5;
			fRec8[0] = fSlow2 + fConst2 * fRec8[1];
			float fTemp7 = 1.0f / std::tan(fConst3 * (1e+04f * fRec8[0] + 1e+02f));
			float fTemp8 = float(input1[i0]);
			fRec10[0] = fSlow3 + fConst2 * fRec10[1];
			float fTemp9 = (fTemp0 + fTemp8) * (1.0f - fRec10[0]) + (fTemp0 - fTemp8) * fRec10[0];
			fVec0[0] = fTemp9;
			float fTemp10 = 1.0f - fTemp3;
			fRec9[0] = 0.5f * (fTemp9 / fTemp5 + fVec0[1] * fTemp6) - fTemp10 * fRec9[1] / fTemp4;
			fRec11[0] = fSlow4 + fConst2 * fRec11[1];
			float fTemp11 = fRec9[0] * fRec11[0];
			fVec1[0] = fTemp11;
			float fTemp12 = fTemp11 + fVec1[1];
			fRec7[IOTA0 & 32767] = 0.0f - (fRec7[(IOTA0 - 1) & 32767] * (1.0f - fTemp7) - fTemp12) / (fTemp7 + 1.0f);
			fRec12[0] = fSlow5 + fConst2 * fRec12[1];
			int iTemp13 = int(std::min<float>(3e+04f, std::max<float>(0.0f, fConst4 * fRec12[0] + 1e+01f)));
			float fTemp14 = fRec7[(IOTA0 - iTemp13) & 32767] - 0.15f * fRec5[1];
			fVec2[IOTA0 & 32767] = fTemp14;
			fRec13[0] = fSlow6 + fConst2 * fRec13[1];
			float fTemp15 = fConst5 * fRec13[0];
			fRec5[0] = fVec2[(IOTA0 - int(std::min<float>(3e+04f, std::max<float>(0.0f, fTemp15 + 9.0f)))) & 32767];
			fRec6[0] = fTemp14;
			fRec14[0] = fSlow7 + fConst2 * fRec14[1];
			float fTemp16 = 1.9e+04f * fRec14[0];
			float fTemp17 = 1.0f / std::tan(fConst3 * (fTemp16 + 1e+01f));
			fRec4[0] = (0.85f * (fRec6[1] + fRec6[2]) - fRec4[1] * (1.0f - fTemp17)) / (fTemp17 + 1.0f);
			fVec3[IOTA0 & 16383] = fRec4[0] + 0.85f * fRec3[1];
			fRec15[0] = fSlow8 + fConst2 * fRec15[1];
			fRec3[0] = fVec3[(IOTA0 - int(std::min<float>(1e+04f, std::max<float>(0.0f, fConst6 * fRec15[0] + 1e+01f)))) & 16383];
			float fTemp18 = (1.0f - fRec11[0]) * fTemp9;
			fVec4[0] = fTemp18;
			float fTemp19 = 0.5f * (fTemp18 + fVec4[1]);
			float fTemp20 = 1.0f / std::tan(fConst3 * (8.5e+03f * fRec8[0] + 85.0f));
			fRec20[IOTA0 & 32767] = (fTemp19 - fRec20[(IOTA0 - 1) & 32767] * (1.0f - fTemp20)) / (fTemp20 + 1.0f);
			float fTemp21 = fConst7 * fRec12[0];
			float fTemp22 = fRec20[(IOTA0 - int(std::min<float>(3e+04f, std::max<float>(0.0f, fTemp21 + 3e+01f)))) & 32767] - 0.45f * fRec18[1];
			fVec5[IOTA0 & 32767] = fTemp22;
			int iTemp23 = int(std::min<float>(3e+04f, std::max<float>(0.0f, fConst8 * fRec13[0] + 7.0f)));
			fRec18[0] = fVec5[(IOTA0 - iTemp23) & 32767];
			fRec19[0] = fTemp22;
			float fTemp24 = 1.0f / std::tan(fConst3 * (fTemp16 + 3e+01f));
			fRec17[0] = (0.55f * (fRec19[1] + fRec19[2]) - fRec17[1] * (1.0f - fTemp24)) / (fTemp24 + 1.0f);
			fVec6[IOTA0 & 16383] = fRec17[0] + 0.85f * fRec16[1];
			float fTemp25 = fConst9 * fRec15[0];
			int iTemp26 = int(std::min<float>(1e+04f, std::max<float>(0.0f, fTemp25 + 8.0f)));
			fRec16[0] = fVec6[(IOTA0 - iTemp26) & 16383];
			int iTemp27 = int(std::min<float>(3e+04f, std::max<float>(0.0f, fConst10 * fRec12[0] + 2e+01f)));
			float fTemp28 = fRec7[(IOTA0 - iTemp27) & 32767] - 0.11f * fRec23[1];
			fVec7[IOTA0 & 32767] = fTemp28;
			float fTemp29 = fConst11 * fRec13[0];
			fRec23[0] = fVec7[(IOTA0 - int(std::min<float>(3e+04f, std::max<float>(0.0f, fTemp29 + 19.0f)))) & 32767];
			fRec24[0] = fTemp28;
			float fTemp30 = 1.0f / std::tan(fConst3 * (fTemp16 + 5e+01f));
			fRec22[0] = (0.89f * (fRec24[1] + fRec24[2]) - fRec22[1] * (1.0f - fTemp30)) / (fTemp30 + 1.0f);
			fVec8[IOTA0 & 16383] = fRec22[0] + 0.75f * fRec21[1];
			fRec21[0] = fVec8[(IOTA0 - int(std::min<float>(1e+04f, std::max<float>(0.0f, fTemp25 + 2e+01f)))) & 16383];
			float fTemp31 = 1.0f / std::tan(fConst3 * (9.5e+03f * fRec8[0] + 95.0f));
			fRec29[IOTA0 & 32767] = (fTemp19 - fRec29[(IOTA0 - 1) & 32767] * (1.0f - fTemp31)) / (fTemp31 + 1.0f);
			float fTemp32 = fRec29[(IOTA0 - int(std::min<float>(3e+04f, std::max<float>(0.0f, fTemp21 + 1e+01f)))) & 32767] - 0.11f * fRec27[1];
			fVec9[IOTA0 & 32767] = fTemp32;
			fRec27[0] = fVec9[(IOTA0 - iTemp23) & 32767];
			fRec28[0] = fTemp32;
			float fTemp33 = 1.0f / std::tan(fConst3 * (fTemp16 + 7e+01f));
			fRec26[0] = (0.89f * (fRec28[1] + fRec28[2]) - fRec26[1] * (1.0f - fTemp33)) / (fTemp33 + 1.0f);
			fVec10[IOTA0 & 16383] = fRec26[0] + 0.85f * fRec25[1];
			fRec25[0] = fVec10[(IOTA0 - iTemp26) & 16383];
			float fTemp34 = fRec3[0] + fRec16[0] + fRec21[0] + fRec25[0];
			fRec30[0] = fSlow9 + fConst2 * fRec30[1];
			float fTemp35 = fTemp34 * fRec30[0];
			fVec11[0] = fTemp35;
			fRec1[0] = fTemp6 * fVec11[1] - (fRec1[1] * fTemp10 - fTemp35 / fTemp2) / fTemp4;
			float fTemp36 = 1.0f - fRec30[0];
			output0[i0] = FAUSTFLOAT(fTemp0 * fTemp1 + fRec0[0] * (fRec1[0] + fTemp34 * fTemp36));
			float fTemp37 = 1.0f / std::tan(fConst3 * (9e+03f * fRec8[0] + 9e+01f));
			fRec36[IOTA0 & 32767] = 0.0f - (fRec36[(IOTA0 - 1) & 32767] * (1.0f - fTemp37) - fTemp12) / (fTemp37 + 1.0f);
			float fTemp38 = fRec36[(IOTA0 - iTemp27) & 32767] - 0.15f * fRec34[1];
			fVec12[IOTA0 & 32767] = fTemp38;
			int iTemp39 = int(std::min<float>(3e+04f, std::max<float>(0.0f, fTemp29 + 4.0f)));
			fRec34[0] = fVec12[(IOTA0 - iTemp39) & 32767];
			fRec35[0] = fTemp38;
			float fTemp40 = 1.0f / std::tan(fConst3 * (fTemp16 + 2e+01f));
			fRec33[0] = (0.85f * (fRec35[1] + fRec35[2]) - fRec33[1] * (1.0f - fTemp40)) / (fTemp40 + 1.0f);
			fVec13[IOTA0 & 16383] = fRec33[0] + 0.75f * fRec32[1];
			fRec32[0] = fVec13[(IOTA0 - int(std::min<float>(1e+04f, std::max<float>(0.0f, fConst12 * fRec15[0] + 5.0f)))) & 16383];
			float fTemp41 = 1.0f / std::tan(fConst3 * (8.9e+03f * fRec8[0] + 89.0f));
			fRec41[IOTA0 & 32767] = (fTemp19 - fRec41[(IOTA0 - 1) & 32767] * (1.0f - fTemp41)) / (fTemp41 + 1.0f);
			float fTemp42 = fRec41[(IOTA0 - iTemp13) & 32767] - 0.16f * fRec39[1];
			fVec14[IOTA0 & 32767] = fTemp42;
			fRec39[0] = fVec14[(IOTA0 - int(std::min<float>(3e+04f, std::max<float>(0.0f, fTemp15 + 15.0f)))) & 32767];
			fRec40[0] = fTemp42;
			float fTemp43 = 1.0f / std::tan(fConst3 * (fTemp16 + 4e+01f));
			fRec38[0] = (0.84f * (fRec40[1] + fRec40[2]) - fRec38[1] * (1.0f - fTemp43)) / (fTemp43 + 1.0f);
			fVec15[IOTA0 & 16383] = fRec38[0] + 0.84f * fRec37[1];
			float fTemp44 = fConst13 * fRec15[0];
			fRec37[0] = fVec15[(IOTA0 - int(std::min<float>(1e+04f, std::max<float>(0.0f, fTemp44 + 16.0f)))) & 16383];
			float fTemp45 = 1.0f / std::tan(fConst3 * (8666.0f * fRec8[0] + 86.0f));
			fRec46[IOTA0 & 32767] = 0.0f - (fRec46[(IOTA0 - 1) & 32767] * (1.0f - fTemp45) - fTemp12) / (fTemp45 + 1.0f);
			float fTemp46 = fRec46[(IOTA0 - int(std::min<float>(3e+04f, std::max<float>(0.0f, fConst14 * fRec12[0] + 2e+01f)))) & 32767] - 0.25f * fRec44[1];
			fVec16[IOTA0 & 32767] = fTemp46;
			fRec44[0] = fVec16[(IOTA0 - int(std::min<float>(3e+04f, std::max<float>(0.0f, fConst15 * fRec13[0] + 9.0f)))) & 32767];
			fRec45[0] = fTemp46;
			float fTemp47 = 1.0f / std::tan(fConst3 * (fTemp16 + 6e+01f));
			fRec43[0] = (0.75f * (fRec45[1] + fRec45[2]) - fRec43[1] * (1.0f - fTemp47)) / (fTemp47 + 1.0f);
			fVec17[IOTA0 & 16383] = fRec43[0] + 0.85f * fRec42[1];
			fRec42[0] = fVec17[(IOTA0 - int(std::min<float>(1e+04f, std::max<float>(0.0f, fTemp44 + 1e+01f)))) & 16383];
			float fTemp48 = 1.0f / std::tan(fConst3 * (9999.0f * fRec8[0] + 99.0f));
			fRec51[IOTA0 & 32767] = (fTemp19 - fRec51[(IOTA0 - 1) & 32767] * (1.0f - fTemp48)) / (fTemp48 + 1.0f);
			float fTemp49 = fRec51[(IOTA0 - iTemp27) & 32767] - 0.07f * fRec49[1];
			fVec18[IOTA0 & 32767] = fTemp49;
			fRec49[0] = fVec18[(IOTA0 - iTemp39) & 32767];
			fRec50[0] = fTemp49;
			float fTemp50 = 1.0f / std::tan(fConst3 * (fTemp16 + 8e+01f));
			fRec48[0] = (0.93f * (fRec50[1] + fRec50[2]) - fRec48[1] * (1.0f - fTemp50)) / (fTemp50 + 1.0f);
			fVec19[IOTA0 & 16383] = fRec48[0] + 0.75f * fRec47[1];
			fRec47[0] = fVec19[(IOTA0 - int(std::min<float>(1e+04f, std::max<float>(0.0f, fConst16 * fRec15[0] + 5.0f)))) & 16383];
			float fTemp51 = fRec32[0] + fRec37[0] + fRec42[0] + fRec47[0];
			float fTemp52 = fRec30[0] * fTemp51;
			fVec20[0] = fTemp52;
			fRec31[0] = fTemp6 * fVec20[1] - (fTemp10 * fRec31[1] - fTemp52 / fTemp2) / fTemp4;
			output1[i0] = FAUSTFLOAT(fTemp8 * fTemp1 + fRec0[0] * (fRec31[0] + fTemp51 * fTemp36));
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
			IOTA0 = IOTA0 + 1;
			fRec8[1] = fRec8[0];
			fRec10[1] = fRec10[0];
			fVec0[1] = fVec0[0];
			fRec9[1] = fRec9[0];
			fRec11[1] = fRec11[0];
			fVec1[1] = fVec1[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec14[1] = fRec14[0];
			fRec4[1] = fRec4[0];
			fRec15[1] = fRec15[0];
			fRec3[1] = fRec3[0];
			fVec4[1] = fVec4[0];
			fRec18[1] = fRec18[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			fRec23[1] = fRec23[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec27[1] = fRec27[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec30[1] = fRec30[0];
			fVec11[1] = fVec11[0];
			fRec1[1] = fRec1[0];
			fRec34[1] = fRec34[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec39[1] = fRec39[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec44[1] = fRec44[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec49[1] = fRec49[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fVec20[1] = fVec20[0];
			fRec31[1] = fRec31[0];
		}
	}

};

// END-FAUSTDSP

#endif
