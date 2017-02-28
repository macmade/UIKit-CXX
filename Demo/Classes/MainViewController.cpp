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

#include "MainViewController.hpp"

namespace Demo
{
    void MainViewController::registerClass( void )
    {
        static std::once_flag once;
        
        std::call_once
        (
            once,
            []
            {
                OBJCXX::ClassBuilder cls( "MainViewController", "UIViewController" );
                
                cls.instanceMethod< MainViewController, void                     >( "viewDidLoad",             &MainViewController::viewDidLoad,              "" ).add();
                cls.instanceMethod< MainViewController, void                     >( "didReceiveMemoryWarning", &MainViewController::didReceiveMemoryWarning , "" ).add();
                cls.instanceMethod< MainViewController, void, const NS::Object & >( "buttonClicked:",          &MainViewController::buttonClicked, "" ).add< void, id >();
                cls.registerClass();
            }
        );
    }
    
    MainViewController::MainViewController( void ):
        UI::ViewController
        (
            "MainViewController",
            [ = ]
            {
                return this->message< id >( "init" ).send();
            }
        )
    {}
    
    void MainViewController::viewDidLoad( void )
    {
        UI::Button btn( UI::Button::buttonWithType( UI::Button::Type::System ) );
        
        NS::Log( "%@", static_cast< id >( *( this ) ) );
        
        btn.setTitleForState( "Click me...", UI::Control::State::Normal );
        btn.sizeToFit();
        btn.setCenter( this->view().center() );
        btn.addTargetActionForControlEvents( *( this ), OBJCXX::RT::GetSelector( "buttonClicked:" ), UI::Control::Events::TouchUpInside );
        this->view().addSubview( btn );
    }
    
    void MainViewController::didReceiveMemoryWarning( void )
    {
        NS::Log( "%@", static_cast< id >( *( this ) ) );
    }
    
    void MainViewController::buttonClicked( const NS::Object & sender )
    {
        UI::AlertView alert( "UIKit++", "hello, world", nullptr, "OK" );
        
        NS::Log( "%@", static_cast< id >( sender ) );
        alert.show();
    }
}
