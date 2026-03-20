from nltk.chat.util import Chat, reflections

# Pairs is a list of patterns and responses
# %1, %2 are "wildcards" that capture what the user says
pairs = [
    [
        r"my name is (.*)",
        ["Hello %1, how can I help you today?",]
    ],
    [
        r"hi|hello|hey",
        ["Hello!", "Hey there!",]
    ],
    [
        r"what is your name?",
        ["I am a chatbot created in Pydroid 3.",]
    ],
    [
        r"how are you?",
        ["I'm doing great! How about you?",]
    ],
    [
        r"sorry (.*)",
        ["Its alright","No problem",]
    ],
    [
        r"quit",
        ["Bye! Take care.","It was nice talking to you. See ya!"]
    ],
    
    [
        r"Are you ready",
        ["yes, i am ready!"]
    ],
    
    [
        r"(.*)",
        ["That's interesting! Tell me more.", "I'm not sure I understand, but keep going."]
    ]
]

def start_chat():
    print("--- AI Chatbot (Type 'quit' to stop) ---")
    chat = Chat(pairs, reflections)
    chat.converse()

if __name__ == "__main__":
    start_chat()

            
            