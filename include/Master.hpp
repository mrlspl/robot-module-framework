/*
 *  The MIT License (MIT)
 *
 *  Copyright (c) 2015 MRL-SPL RoboCup Team
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *
 */
#ifndef ROBOT_MODULE_FRAMEWORK_ROUTE_HPP
#define ROBOT_MODULE_FRAMEWORK_ROUTE_HPP

#include "Node.hpp"
#include <string>


namespace RMF::Internal
{
    /**
     *  \class Route_
     *  \brief     Internal class to represent connections between topics provided and listened internally by nodes and in global space of a Master.
     *  \author <a href="mailto:a.sharpasand@mrl-spl.ir">Mohammad Ali Sharpasand</a>
     *  \version   0.0.1
     *  \copyright MIT License.
     */
    class Route_
    {
    public:
        Node node;
        std::string internalTopic;
        std::string publicTopic;
    };

}

#endif //ROBOT_MODULE_FRAMEWORK_ROUTE_HPP
