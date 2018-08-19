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
#ifndef ROBOT_MODULE_FRAMEWORK_MASTER_HPP
#define ROBOT_MODULE_FRAMEWORK_MASTER_HPP

#include <map>
#include <string>
#include "Node.hpp"

namespace RMF
{

    namespace Internal
    {
        class Route;
    }

    /**
     *  \class Master Master.hpp
     *  \brief     Master is the coordinator for a set of Nodes.
     *
     *  Nodes should be registered on it to be fed with topics and provide topics or services. Master then runs them appropriately.
     *
     *  \author <a href="mailto:a.sharpasand@mrl-spl.ir">Mohammad Ali Sharpasand</a>
     *  \version   0.0.1
     *  \copyright MIT License.
     */
    class Master
    {
    public:
        /**
         * Registers Nodes on master.
         * \remark They need to be registerd as publisher or subscriber later.
         */
        void registerNode();

        /**
         * Registers a Node as publisher on an specific Topic.
         * \pre The Node should be registered on the master.
         */
        void registerPublisher();

        /**
         * Registers a Node as a subscriber.
         * \pre The Node should be registered on the master.
         */
        void registerSubscriber();

        /**
         * Run a loop on all registered nodes.
         */
        void update();

    private:
        std::map<std::string, Internal::Route> publishers_;
        std::map<std::string, Internal::Route> subscribers_;
    };
}

#endif //ROBOT_MODULE_FRAMEWORK_MASTER_HPP
