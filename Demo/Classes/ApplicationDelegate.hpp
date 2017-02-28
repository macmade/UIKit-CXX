/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015 Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/*!
 * @copyright   (c) 2015 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @brief       ...
 */

#include <OBJCXX.hpp>
#include <UIKit.hpp>

namespace Demo
{
    class ApplicationDelegate: public NS::Object
    {
        public:
            
            OBJCXX_USING_BASE( ApplicationDelegate, NS::Object )
            
            static void registerClass( void );
            
            UI::Window window( void ) const;
            void       setWindow( const UI::Window & value );
            
            bool applicationDidFinishLaunchingWithOptions( const UI::Application & application, const NS::Dictionary & launchOptions );
            void applicationWillResignActive( const UI::Application & application );
            void applicationDidEnterBackground( const UI::Application & application );
            void applicationWillEnterForeground( const UI::Application & application );
            void applicationDidBecomeActive( const UI::Application & application );
            void applicationWillTerminate( const UI::Application & application );
            
        private:
            
            ApplicationDelegate( void ) = default;
    };
}
