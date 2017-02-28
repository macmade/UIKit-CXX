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

#include "ApplicationDelegate.hpp"
#include <mutex>

namespace Demo
{
    void ApplicationDelegate::registerClass( void )
    {
        static std::once_flag once;
        
        std::call_once
        (
            once,
            []
            {
                OBJCXX::ClassBuilder cls( "ApplicationDelegate", "NSObject" );
                
                cls.addProperty( "window", OBJCXX::ClassBuilder::TypeObject );
                cls.instanceMethod< ApplicationDelegate, bool, const UI::Application &, const NS::Dictionary & >( "application:didFinishLaunchingWithOptions:", &ApplicationDelegate::applicationDidFinishLaunchingWithOptions, "" ).add< bool, id, id >();
                cls.instanceMethod< ApplicationDelegate, void, const UI::Application & >( "applicationWillResignActive:",    &ApplicationDelegate::applicationWillResignActive,    "" ).add< void, id >();
                cls.instanceMethod< ApplicationDelegate, void, const UI::Application & >( "applicationDidEnterBackground:",  &ApplicationDelegate::applicationDidEnterBackground , "" ).add< void, id >();
                cls.instanceMethod< ApplicationDelegate, void, const UI::Application & >( "applicationWillEnterForeground:", &ApplicationDelegate::applicationWillEnterForeground, "" ).add< void, id >();
                cls.instanceMethod< ApplicationDelegate, void, const UI::Application & >( "applicationDidBecomeActive:",     &ApplicationDelegate::applicationDidBecomeActive,     "" ).add< void, id >();
                cls.instanceMethod< ApplicationDelegate, void, const UI::Application & >( "applicationWillTerminate:",       &ApplicationDelegate::applicationWillTerminate,       "" ).add< void, id >();
                cls.registerClass();
            }
        );
    }
    
    UI::Window ApplicationDelegate::window( void ) const
    {
        return this->message< id >( "window" ).send();
    }
    
    void ApplicationDelegate::setWindow( const UI::Window & value )
    {
        this->message< void >( "setWindow:" ).send< id >( value );
    }
    
    bool ApplicationDelegate::applicationDidFinishLaunchingWithOptions( const UI::Application & application, const NS::Dictionary & launchOptions )
    {
        std::cout << application << std::endl;
        
        if( launchOptions != nullptr )
        {
            std::cout << launchOptions << std::endl;
        }
        
        return true;
    }
    
    void ApplicationDelegate::applicationWillResignActive( const UI::Application & application )
    {
        std::cout << application << std::endl;
    }
    
    void ApplicationDelegate::applicationDidEnterBackground( const UI::Application & application )
    {
        std::cout << application << std::endl;
    }
    
    void ApplicationDelegate::applicationWillEnterForeground( const UI::Application & application )
    {
        std::cout << application << std::endl;
    }
    
    void ApplicationDelegate::applicationDidBecomeActive( const UI::Application & application )
    {
        std::cout << application << std::endl;
    }
    
    void ApplicationDelegate::applicationWillTerminate( const UI::Application & application )
    {
        std::cout << application << std::endl;
    }
}
