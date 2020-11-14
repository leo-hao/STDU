import re
import jieba
from sklearn.feature_extraction.text import TfidfVectorizer

corpus = []
with open("news.txt", "r", encoding="utf-8") as news_file:
    corpus = [line for line in news_file.readlines()]

X_train = []
with open("news_jieba.txt", "w", encoding="utf-8") as news_file:
    for text in corpus:
        news_file.write("{}\n".format(" ".join(jieba.cut(text))))
        X_train.append(" ".join(jieba.cut(text)))

vectorizer = TfidfVectorizer()
vectorizer.fit(X_train)  # 用X_train数据来fit
tfidf_train = vectorizer.transform(X_train)  # 得到tfidf的矩阵
print(vectorizer.vocabulary_)  # 显示词表
print(tfidf_train.toarray())  # 显示tfidf矩阵

words = vectorizer.vocabulary_
tfidf_array = tfidf_train.toarray()

for value in tfidf_array:
    print(value[words["深化改革"]])
