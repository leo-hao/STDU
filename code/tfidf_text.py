from sklearn.feature_extraction.text import TfidfTransformer
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.feature_extraction.text import TfidfVectorizer


X_train = [
    'This is the first document.',
    'This is the second document.',
    'This is the third document.',
    'This is the third document.'
]
vectorizer = TfidfVectorizer()
vectorizer.fit(X_train) # 用X_train数据来fit
tfidf_train = vectorizer.transform(X_train) # 得到tfidf的矩阵
print(vectorizer.vocabulary_) # 显示词表
print(tfidf_train.toarray()) # 显示tfidf矩阵
