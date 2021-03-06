//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DirectUnknown.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX;

    /// <summary>
    /// An information-queue interface stores, retrieves, and filters debug messages. The queue consists of a message queue, an optional storage filter stack, and a optional retrieval filter stack.
    /// <para>(Also see DirectX SDK: ID3D10InfoQueue)</para>
    /// </summary>
    public ref class InfoQueue :
        public DirectUnknown
    {
    public: 
        /// <summary>
        /// Add a user-defined message to the message queue and send that message to debug output.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::AddApplicationMessage)</para>
        /// </summary>
        /// <param name="severity">Severity of a message (see <see cref="MessageSeverity"/>)<seealso cref="MessageSeverity"/>.</param>
        /// <param name="description">Message string.</param>
        void AddApplicationMessage(MessageSeverity severity, String^ description);

        /// <summary>
        /// Add a Direct3D 10 debug message to the message queue and send that message to debug output.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::AddMessage)</para>
        /// </summary>
        /// <param name="category">Category of a message (see <see cref="MessageCategory"/>)<seealso cref="MessageCategory"/>.</param>
        /// <param name="severity">Severity of a message (see <see cref="MessageSeverity"/>)<seealso cref="MessageSeverity"/>.</param>
        /// <param name="id">Unique identifier of a message (see <see cref="MessageId"/>)<seealso cref="MessageId"/>.</param>
        /// <param name="description">User-defined message.</param>
        void AddMessage(MessageCategory category, MessageSeverity severity, MessageId id, String^ description);

        /// <summary>
        /// Clear all messages from the message queue.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::ClearStoredMessages)</para>
        /// </summary>
        void ClearStoredMessages();

        /// <summary>
        /// Get a message category to break on when a message with that category passes through the storage filter.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::GetBreakOnCategory)</para>
        /// </summary>
        /// <param name="category">Message category to break on (see <see cref="MessageCategory"/>)<seealso cref="MessageCategory"/>.</param>
        Boolean GetBreakOnCategory(MessageCategory category);

        /// <summary>
        /// Get a message identifier to break on when a message with that identifier passes through the storage filter.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::GetBreakOnID)</para>
        /// </summary>
        /// <param name="id">Message identifier to break on (see <see cref="MessageId"/>)<seealso cref="MessageId"/>.</param>
        Boolean GetBreakOnId(MessageId id);

        /// <summary>
        /// Get a message severity level to break on when a message with that severity level passes through the storage filter.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::GetBreakOnSeverity)</para>
        /// </summary>
        /// <param name="severity">Message severity level to break on (see <see cref="MessageSeverity"/>)<seealso cref="MessageSeverity"/>.</param>
        Boolean GetBreakOnSeverity(MessageSeverity severity);

        /// <summary>
        /// Get a message from the message queue.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::GetMessage)</para>
        /// </summary>
        /// <param name="messageIndex">Index into message queue after an optional retrieval filter has been applied. 
        /// This can be between 0 and the number of messages in the message queue that pass through the retrieval filter (which can be obtained with GetNumStoredMessagesAllowedByRetrievalFilter(). 
        /// 0 is the message at the front of the message queue.</param>
        /// <returns>Returned message (see <see cref="Message"/>)<seealso cref="Message"/>.</returns>
        Message GetMessage(UInt64 messageIndex);

        /// <summary>
        /// Try to get a message from the message queue.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::GetMessage)</para>
        /// </summary>
        /// <param name="messageIndex">Index into message queue after an optional retrieval filter has been applied. 
        /// This can be between 0 and the number of messages in the message queue that pass through the retrieval filter 
        /// (which can be obtained with NumStoredMessagesAllowedByRetrievalFilter property. 
        /// Index 0 is the message at the front of the message queue. </param>        
        /// <param name="message">Returned message (see <see cref="Message"/>)<seealso cref="Message"/>.</param>      
        /// <returns>True if successful; false otherwise.</returns>
        Boolean TryGetMessage(UInt64 messageIndex, [System::Runtime::InteropServices::Out]  Message % message);

        /// <summary>
        /// Get or set the maximum number of messages that can be added to the message queue.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::GetMessageCountLimit)</para>
        /// </summary>
        property UInt64 MessageCountLimit
        {
            UInt64 get();
            void set(UInt64);
        }

        /// <summary>
        /// Get or set a boolean that turns the debug output on or off.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::GetMuteDebugOutput)</para>
        /// </summary>
        property Boolean MuteDebugOutput
        {
            Boolean get();
            void set(Boolean);
        }

        /// <summary>
        /// Get the number of messages that were allowed to pass through a storage filter.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::GetNumMessagesAllowedByStorageFilter)</para>
        /// </summary>
        property UInt64 NumMessagesAllowedByStorageFilter
        {
            UInt64 get();
        }

        /// <summary>
        /// Get the number of messages that were denied passage through a storage filter.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::GetNumMessagesDeniedByStorageFilter)</para>
        /// </summary>
        property UInt64 NumMessagesDeniedByStorageFilter
        {
            UInt64 get();
        }

        /// <summary>
        /// Get the number of messages that were discarded due to the message count limit.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::GetNumMessagesDiscardedByMessageCountLimit)</para>
        /// </summary>
        property UInt64 NumMessagesDiscardedByMessageCountLimit
        {
            UInt64 get();
        }


        /// <summary>
        /// Get the number of messages currently stored in the message queue.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::GetNumStoredMessages)</para>
        /// </summary>
        property UInt64 NumStoredMessages
        {
            UInt64 get();
        }

        /// <summary>
        /// Get the number of messages that are able to pass through a retrieval filter.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::GetNumStoredMessagesAllowedByRetrievalFilter)</para>
        /// </summary>
        property UInt64 NumStoredMessagesAllowedByRetrievalFilter
        {
            UInt64 get();
        }

        /// <summary>
        /// Set a message category to break on when a message with that category passes through the storage filter.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::SetBreakOnCategory)</para>
        /// </summary>
        /// <param name="category">Message category to break on (see <see cref="MessageCategory"/>)<seealso cref="MessageCategory"/>.</param>
        /// <param name="enable">Turns this breaking condition on or off (true for on, false for off).</param>
        void SetBreakOnCategory(MessageCategory category, Boolean enable);

        /// <summary>
        /// Set a message identifier to break on when a message with that identifier passes through the storage filter.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::SetBreakOnID)</para>
        /// </summary>
        /// <param name="id">Message identifier to break on (see <see cref="MessageId"/>)<seealso cref="MessageId"/>.</param>
        /// <param name="enable">Turns this breaking condition on or off (true for on, false for off).</param>
        void SetBreakOnId(MessageId id, Boolean enable);

        /// <summary>
        /// Set a message severity level to break on when a message with that severity level passes through the storage filter.
        /// <para>(Also see DirectX SDK: ID3D10InfoQueue::SetBreakOnSeverity)</para>
        /// </summary>
        /// <param name="severity">Message severity level to break on (see <see cref="MessageSeverity"/>)<seealso cref="MessageSeverity"/>.</param>
        /// <param name="enable">Turns this breaking condition on or off (true for on, false for off).</param>
        void SetBreakOnSeverity(MessageSeverity severity, Boolean enable);

    internal:
        InfoQueue()
        { }

        InfoQueue(ID3D10InfoQueue* pNativeID3D10InfoQueue) : 
            DirectUnknown(pNativeID3D10InfoQueue)
        { }
    };
} } } }
